#ifndef MIXED_SHAPE_H
#define MIXED_SHAPE_H
#include "shape.h"
#include "shape_iterator.h"
#include "iterator.h"
#include <list>
class MixedShape : public Shape {
public:
  MixedShape(){

  }

  double area() const{
    double totalArea = 0.0;
    for(auto shape : _shapes){
      totalArea += shape->area();
    }
    return totalArea;
  }

  int getNumberOfComponents() {
    return _shapes.size();
  }

  void add(Shape * shape){
    _shapes.push_back(shape);
  }

  Iterator * createIterator() {
    return new ShapeIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
  }

  void accept(FindFirstVisitor &ffv) {
    ffv.visitMixedShape(this);
  }
  
private:
  std::list<Shape *> _shapes;

};

#endif
