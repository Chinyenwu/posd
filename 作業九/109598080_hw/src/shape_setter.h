#ifndef SHAPE_SETTER
#define SHAPE_SETTER
#include "filter.h"

typedef void (*Setter)(Shape *);

class ShapeSetter : public Filter {
public:

    ShapeSetter( Setter set ):_set(set),_next(nullptr) {}
        // `Setter` is a template name for lambda,
        //  you may use your own name.

    Filter* setNext(Filter* filter) {
        // seeting next filter.
        _next = filter;
        return _next;
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
        // push down setted data and return result.
        std::list<Shape *>::iterator it = shapes.begin();
        std::list<Shape *>::iterator it2 = shapes.end();
        std::list<Shape *> _result;
        while (it!=it2) {
            _set((*it));
            _result.push_back((*it));

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
    Setter _set;
    Filter * _next;
};
#endif
