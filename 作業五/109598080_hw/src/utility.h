#ifndef UTILITY
#define UTILITY
#include "shape.h"
#include "shape_iterator.h"
#include "compound_shape.h"
#include <deque>
double big,small;
std::string check;
class AreaFilter {
public:
    AreaFilter(double upperBound, double lowerBound) {
        big = upperBound;
        small  = lowerBound;
    }
    bool operator() (Shape* shape) const {
        if(shape->area()>small&&shape->area()<big){
          return 1;
        }
        else{
          return 0;
        }
    }
};

class PerimeterFilter {
  public:
    PerimeterFilter(double upperBound, double lowerBound) {
      big = upperBound;
      small  = lowerBound;
    }
    bool operator() (Shape* shape) const {
      if(shape->perimeter()>small&&shape->perimeter()<big){
        return 1;
      }
      else{
        return 0;
      }
    }
};

class ColorFilter {
  public:
    ColorFilter(std::string color) {
        check = color;
    }
    bool operator() (Shape* shape) const {
      if(shape->color()==check){
        return 1;
      }
      else{
        return 0;
      }
    }
};

class TypeFilter {
  public:
    TypeFilter(std::string type) {
        check = type;
    }
    bool operator() (Shape* shape) const {
      if(shape->type()==check){
        return 1;
      }
      else{
        return 0;
      }
    }
};

Shape* getShapeById(Shape* shape, std::string id) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return a shape under the input shape tree sturcture that matches the id.
    // throw std::string "Only compound shape can get shape!" when the input shape is not iterable.
    // throw std::string "Expected get shape but shape not found" when no shape found with the given id.
    Iterator * it = shape->createIterator();
    int tag1=0;
    if(it->isDone()){
      throw std::string ("Only compound shape can get shape!");
    }
    while (!it->isDone()) {
      if(it->currentItem()->id()==id){
        tag1=1;
        return it->currentItem();
      }
      else{
        try {
          getShapeById(it->currentItem(),id);
          if(getShapeById(it->currentItem(),id)->id()==id){
            tag1=1;
            return (getShapeById(it->currentItem(),id));
          }
          }catch(std::string e) {

          }
      }
      it->next();
    }

    if(tag1==0){
      throw std::string("Expected get shape but shape not found");
    }
}

template <class Filter>
std::deque<Shape*> filterShape(Shape* shape, Filter filter) {
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturctur that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
    std::deque<Shape*> deq = {};
    std::deque<Shape*> deq2 = {};
    Iterator * it = shape->createIterator();
    if(it->isDone()){
      throw std::string ("Only compound shape can filter shape!");
    }
      while (!it->isDone()) {
          if(filter.operator()(it->currentItem())){
            //std::cout << "get" << '\n';
            deq.push_back(it->currentItem());
          }
          try{
            deq2 = filterShape(it->currentItem(), filter);
            std::deque<Shape*>::iterator it1 = deq2.begin();
            std::deque<Shape*>::iterator it2 = deq2.end();
            for(it1;it1!=it2;it1++){
              deq.push_back(*it1);
            }
          }catch(std::string e){}
          it->next();
      }
    return deq;
}

#endif
