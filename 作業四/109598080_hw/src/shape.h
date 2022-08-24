#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <vector>
#include <fstream>
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    std::string id() const{
      return this->_id;
    }; // return id of shape.
    std::string color() const{
      return this->_color;
    }; // return color of shape.
    virtual void addShape(Shape *shape){
      throw std::string("Only compound shape can add shape!");
    }; // throw std::string "Only compound shape can add shape!"
    virtual void deleteShapeById(std::string id){
      throw std::string("Only compound shape can delete shape!");
    }; // throw std::string "Only compound shape can delete shape!"
    virtual Shape* getShapeById(std::string id){
      throw std::string("Only compound shape can get shape!");
    }; // throw std::string "Only compound shape can get shape!"
    Shape(){};
    Shape(std::string id){
      this->_id=id;
      this->_color="white";
    }; // interface for default color "white".
    Shape(std::string id, std::string color){
      this->_id=id;
      this->_color=color;
    }; // interface for color input by user.

protected:
  std::string _id,_color="transparent";
};
#endif
