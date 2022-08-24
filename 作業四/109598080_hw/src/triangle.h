#ifndef TRIANGLE
#define TRIANGLE
#include "shape.h"
#include "two_dimensional_coordinate.h"
class Triangle: public Shape{
public:
  Triangle(std::string id,std::vector<TwoDimensionalCoordinate*> vectors,std::string color) {
      // If the triangle can't be successfully created,
      // handle the exception by throwing string "This is not a triangle!"
      this->_id = id;
      this->_color = color;
      if(vectors.size()!=3){
        throw std::string("This is not a triangle!");
      }
      x1=vectors[0]->getX();
      x2=vectors[1]->getX();
      x3=vectors[2]->getX();
      y1=vectors[0]->getY();
      y2=vectors[1]->getY();
      y3=vectors[2]->getY();

      x = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
      y = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
      z = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

      if(iswired()>0){
        throw std::string("This is not a triangle!");
      }
      }

      Triangle(std::string id,std::vector<TwoDimensionalCoordinate*> vectors) {
          // If the triangle can't be successfully created,
          // handle the exception by throwing string "This is not a triangle!"
          this->_id = id;
          this->_color = "white";
          if(vectors.size()!=3){
            throw std::string("This is not a triangle!");
          }
          x1=vectors[0]->getX();
          x2=vectors[1]->getX();
          x3=vectors[2]->getX();
          y1=vectors[0]->getY();
          y2=vectors[1]->getY();
          y3=vectors[2]->getY();

          x = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
          y = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
          z = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

          if(iswired()>0){
            throw std::string("This is not a triangle!");
          }
          }

    Triangle(std::vector<TwoDimensionalCoordinate*> vectors) {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
        if(vectors.size()!=3){
          throw std::string("This is not a triangle!");
        }
        x1=vectors[0]->getX();
        x2=vectors[1]->getX();
        x3=vectors[2]->getX();
        y1=vectors[0]->getY();
        y2=vectors[1]->getY();
        y3=vectors[2]->getY();

        x = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        y = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        z = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

        if(iswired()>0){
          throw std::string("This is not a triangle!");
        }
        }

        bool iswired(){
            if(x<=0||y<=0||z<=0){
              return true;
            }
            if(x+y<z||y+z<x||z+x<y){
              return true;
            }
            else{
              return false;
            }
        }

    double area() const {
        // return the area of the Triangle.
        double s = (x + y + z) / 2;
        return sqrt(s * (s - x) * (s - y) * (s - z));
    }

    double perimeter() const {
        // return the perimeter of the Triangle.
        return x+y+z;
    }

    std::string info() const {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
        char str[100];
        sprintf(str, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",x1,y1,x2,y2,x3,y3);
        return str;

    }


  private:
    //data members
    double x,y,z,x1,x2,x3,y1,y2,y3 ;

};
#endif
