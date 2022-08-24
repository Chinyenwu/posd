#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "./shape.h"
#include <math.h>

class Triangle : public Shape {
public:
  Triangle(double a, double b, double c):_a(a),_b(b),_c(c) {} // constructor initialization

  double area() const {
    double s = (_a + _b + _c) / 2;
    return sqrt(s * (s - _a) * (s - _b) * (s - _c));
  }
  void accept(FindFirstVisitor &ffv) {
    ffv.visitTriangle(this);
  }

private:
  double _a, _b, _c;
};
#endif
