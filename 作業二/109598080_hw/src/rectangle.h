#ifndef RECTANGLE
#define RECTANGLE
#include "shape.h"
class Rectangle: public Shape {
public:
  Rectangle(double length, double width) {
    _length = length;
    _width = width;
    // If the rectangle can't be successfully created,
    // handle the exception by throwing string "This is not a rectangle!"
    if(iswired()>0){
      throw std::string("This is not a rectangle!");
    }
  }

  bool iswired(){
      if(_length<=0||_width<=0){
        return true;
      }
      else{
        return false;
      }
  }

  double area() const {
    // return the area of the Rectangle.
    return _width * _length;//後加0.5是四捨五入
  }

  double perimeter() const {
      // return the perimeter of the Rectangle.
    return 2*(_width + _length);
  }

  std::string info() const {
    // return the info of the Rectangle.
    // ex. Rectangle (3.712, 4.000)
    char str[80];
    sprintf(str, "Rectangle (%.3f, %.3f)", _length,_width);
    return str;
  }

private:
  //data members
  double _length,_width ;
};
#endif
