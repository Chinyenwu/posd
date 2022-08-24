#include <iostream>
#include <string>
#include "compound_shape.h"
#include "shape.h"
#include "null_iterator.h"
#include "shape_iterator.h"

std::string Shape::id() const{
  return this->_id;
};
std::string Shape::color() const{
  return this->_color;
};
void Shape::addShape(Shape *shape){
  throw std::string("Only compound shape can add shape!");
}
void Shape::deleteShapeById(std::string id){
  throw std::string("Only compound shape can delete shape!");
};
Shape* Shape::getShapeById(std::string id) const{
  throw std::string("Only compound shape can get shape!");
};
Iterator* Shape::createIterator() const{
  Iterator * nulliterator = new NullIterator();
  //NullIterator* nulliterator;
  return nulliterator;
};

void Shape::setColor(std::string color){
  this->_color=color;
};

Shape::~Shape(){};
Shape::Shape(){};
Shape::Shape(std::string id){
  this->_id=id;
  this->_color="white";
};
Shape::Shape(std::string id, std::string color){
  this->_id=id;
  this->_color=color;
};
