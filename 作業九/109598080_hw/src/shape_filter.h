#ifndef SHAPE_FILTER
#define SHAPE_FILTER
#include "filter.h"

typedef bool (*Predicate)(Shape *);

class ShapeFilter : public Filter {
public:

    ShapeFilter( Predicate pred ):_pred(pred),_next(nullptr){}//這裡可以預設landa參數
        // `Predicate` is a template name for lambda,
        //  you may use your own name.

    Filter* setNext(Filter* filter) {
        // seeting next filter.
        _next = filter;
        return _next;
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
        // push down filtered data and return result.
        std::list<Shape *>::iterator it = shapes.begin();
        std::list<Shape *>::iterator it2 = shapes.end();
        std::list<Shape *> _result;
        while (it!=it2) {
          if(_pred((*it))){
            _result.push_back((*it));
          }
          it++;
        }

        if(_next){
          try{
                _result = _next->push(_result);
            }catch(std::string e){}
        }
        return _result;
    }

private:
  //std::list<Shape *> _shapes;
  Predicate _pred;
  Filter * _next;
};
#endif
