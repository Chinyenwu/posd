#ifndef NODE_ITERATOR
#define NODE_ITERATOR
#include "iterator.h"
template<class ForwardIterator>
class NodeIterator : public Iterator {
public:
  NodeIterator(){

  }
  NodeIterator(ForwardIterator begin, ForwardIterator end) {
        // initialize iterator.
        _begin = begin;
        _end = end;
        _current = begin;
    }

    void first() {
        // initialize iterator.
        _current = _begin;
    }

    void next() {
        // move iterator to next position,
        // throw std::string "Moving past the end!" when iterator move over the range of the structure.
        /*_current = _current + 1;
        if(_current >= _end){
          throw std::string("Moving past the end!");
        }//此方法為vector*/
        if(isDone()){
          throw std::string("Moving past the end!");
        }
        _current++;
    }

    bool isDone() const {
        // return true when iterator reach the end of the structure.
        return _current == _end;
    }

    Node* currentItem() const {
        // return the Node that iterator currently point at.
        return * _current;
    }

  private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};


#endif
