#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <vector>
#include <list>
#include <fstream>
#include "iterator.h"

class Shape {
public:
    Shape();
    Shape(std::string id); // interface for default color "white".
    Shape(std::string id, std::string color); // interface for color input by user.
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual std::string type() const = 0;
    std::string id() const; // return id of shape.
    std::string color() const; // return color of shape.
    virtual void addShape(Shape *shape); // throw std::string "Only compound shape can add shape!"
    virtual void deleteShapeById(std::string id); // throw std::string "Only compound shape can delete shape!"
    virtual Shape* getShapeById(std::string id) const; // throw std::string "Only compound shape can get shape!"
    virtual Iterator* createIterator() const;

    virtual ~Shape();


protected:
  std::string _id,_color="transparent";
};
#endif
