#ifndef MIXED_SHAPE_H
#define MIXED_SHAPE_H
#include "shape.h"
#include "shape_iterator.h"
#include "iterator.h"
#include <list>
#include <sstream>
#include "shape_visitor.h"

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

  Iterator * createIterator() const {
    return new ShapeIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
  }

  void accept(ShapeVisitor &sv) {
    sv.visitMixedShape(this);
  }

  std::string toString() const {
    std::stringstream ss;
    Iterator *it = createIterator();

    ss << "mixed {\n";
    for (it->first(); !it->isDone(); it->next()) {
      Shape *shape = it->currentItem();
      ss << "  " << shape->toString();
    }
    ss << "}\n";
    return ss.str();
  }
private:
  std::list<Shape *> _shapes;

};

#endif
