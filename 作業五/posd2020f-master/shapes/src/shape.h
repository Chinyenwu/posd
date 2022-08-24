#ifndef SHAPE_H
#define SHAPE_H

#include "iterator.h"
#include "null_iterator.h"
#include "find_first_visitor.h"

class Shape {
public:
  virtual void add(Shape * shape) {
    throw (std::string)"Can't support this operation.";
  }
  virtual double area() const = 0;
  virtual Iterator * createIterator() {
    return new NullIterator();
  };
  virtual void accept(FindFirstVisitor &ffv) {}
  virtual ~Shape(){};
};

class AreaSmaller {
public:
  bool operator()(Shape * a, Shape * b) {
    return a->area() < b->area();
  }
};

#endif
