#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "./shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double width, double height) {
    _width = width;
    _height = height;
  }

  double area() const {
    return _width * _height;
  }

  void accept(FindFirstVisitor &ffv) {
    ffv.visitRectangle(this);
  }

private:
  //data members
  double _width, _height;
};
#endif
