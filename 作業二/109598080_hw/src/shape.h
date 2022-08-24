#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <vector>
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
};
#endif
