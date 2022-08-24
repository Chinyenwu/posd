#ifndef TWO_DIMENSIONAL_COORDINATE
#define TWO_DIMENSIONAL_COORDINATE
#include <iostream>
#include <vector>
class TwoDimensionalCoordinate {
public:
    TwoDimensionalCoordinate(double x, double y){
      _x=x;
      _y=y;
    }

    double getX() {
    // return x;
        return _x;
	  }

	  double getY() {
		// return y;
        return _y;
	  }
  private:
    //data members
    double _x,_y;
};
#endif
