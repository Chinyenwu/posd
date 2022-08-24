#include <math.h>

class Triangle {
public:
  Triangle(double a, double b, double c):_a(a),_b(b),_c(c) {} // constructor initialization

  double area() const {
    double s = (_a + _b + _c) / 2;
    return sqrt(s * (s - _a) * (s - _b) * (s - _c));
  }
private:
  double _a, _b, _c;
};
