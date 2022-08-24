#include "shape.h"
class Ellipse: public Shape{
public:
    Ellipse(double semiMajorAxes, double semiMinorAxes) {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
        if(semiMinorAxes > semiMajorAxes){
          _semiMajorAxes = semiMinorAxes;
          _semiMinorAxes = semiMajorAxes;
        }
        else{
          _semiMajorAxes = semiMajorAxes;
          _semiMinorAxes = semiMinorAxes;
        }

        if(iswired()>0){
          throw std::string("This is not a ellipse!");
        }
    }

    bool iswired(){
        if(_semiMajorAxes<=0||_semiMinorAxes<=0){
          return true;
        }
        else{
          return false;
        }
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

  private:
    //data members
    double _semiMajorAxes,_semiMinorAxes;
};
