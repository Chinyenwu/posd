#ifndef ELLIPSE
#define ELLIPSE
#include "shape.h"
class Ellipse: public Shape{
public:
  Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color) {
      // If the ellipse can't be successfully created,
      // handle the exception by throwing string "This is not a ellipse!"
      this->_id = id;
      this->_color = color;
      if(semiMajorAxes<=0||semiMinorAxes<=0){
        throw std::string("This is not an ellipse!");
      }
      if((semiMajorAxes-semiMinorAxes) < 0){
        throw std::string("This is not an ellipse!");
      }

      _semiMajorAxes = semiMajorAxes;
      _semiMinorAxes = semiMinorAxes;

  }

  Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes) {
      // If the ellipse can't be successfully created,
      // handle the exception by throwing string "This is not a ellipse!"
      this->_id = id;
      this->_color = "white";
      if(semiMajorAxes<=0||semiMinorAxes<=0){
        throw std::string("This is not an ellipse!");
      }
      if((semiMajorAxes-semiMinorAxes) < 0){
        throw std::string("This is not an ellipse!");
      }

      _semiMajorAxes = semiMajorAxes;
      _semiMinorAxes = semiMinorAxes;

  }

    Ellipse(double semiMajorAxes, double semiMinorAxes) {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
        if(semiMajorAxes<=0||semiMinorAxes<=0){
          throw std::string("This is not an ellipse!");
        }
        if((semiMajorAxes-semiMinorAxes) < 0){
          throw std::string("This is not an ellipse!");
        }

        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;

    }
    double area() const {
        // return the area of the Ellipse.
        return M_PI*_semiMajorAxes * _semiMinorAxes;
    }

    double perimeter() const {
        // return the perimeter of the Ellipse.
        return (2*M_PI*_semiMinorAxes+4*(_semiMajorAxes - _semiMinorAxes));
    }

    std::string info() const {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
        char str[80];
        sprintf(str, "Ellipse (%.3f, %.3f)", _semiMajorAxes,_semiMinorAxes);
        return str;
    }

    std::string type() const{
        return "Ellipse";
    }

    void accept(Visitor* visitor){
      visitor->visit(this);
    }

  private:
    //data members
    double _semiMajorAxes,_semiMinorAxes;
};
#endif
