#ifndef UTILITY
#define UTILITY
#include "node.h"
#include "node_iterator.h"
#include "folder.h"
#include <deque>
double big,small;
class SizeFilter {
public:
    SizeFilter(double upperBound, double lowerBound) {
        big = upperBound;
        small  = lowerBound;
    }
    bool operator() (Node* node) const {
        if(node->size()>=small&&node->size()<=big){
          return 1;
        }
        else{
          return 0;
        }
    }
};

template <class Filter>
std::deque<Node*> filterNode(Node* node, Filter filter) {
    // access the Node with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the Nodes under the input Node tree sturctur that match the given filter.
    // throw std::string "Only compound Node can filter Node!" when the input Node is not iterable.
    std::deque<Node*> deq = {};
    std::deque<Node*> deq2 = {};
    Iterator * it = node->createIterator();
    if(it->isDone()){
      throw std::string ("Only folder can filter node!");
    }
      while (!it->isDone()) {
          if(filter.operator()(it->currentItem())){
            //std::cout << "get" << '\n';
            deq.push_back(it->currentItem());
          }
          try{
            deq2 = filterNode(it->currentItem(), filter);
            std::deque<Node*>::iterator it1 = deq2.begin();
            std::deque<Node*>::iterator it2 = deq2.end();
            for(it1;it1!=it2;it1++){
              deq.push_back(*it1);
            }
          }catch(std::string e){}
          it->next();
      }
    return deq;
}

#endif
