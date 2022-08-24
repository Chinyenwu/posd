#ifndef COMPOUND_SHAPE
#define COMPOUND_SHAPE
#include "shape.h"
#include "rectangle.h"
#include <typeinfo>
class CompoundShape : public Shape {
public:
        CompoundShape(){

        }
        CompoundShape(std::string id, std::vector<Shape*>* shapes) {
            // The default color of compound shape should be "transparent".
            // When there's no shape contain in the compound shape,
            // should throw std::string "This is not a compound shape!"
            this->_id = id;
            _shapes = *shapes;
            std::vector<Shape *>::iterator it = _shapes.begin();
            std::vector<Shape *>::iterator it2 = _shapes.end();
            if(it==it2){
              throw std::string("This is not a compound shape!");
            }
        }


        double area() const {
            // return sum of all containing shapes area.
            double a=0;
            std::vector<Shape *>::const_iterator it = _shapes.begin();
            std::vector<Shape *>::const_iterator it2 = _shapes.end();
            while (it!=it2) {
              a=a+(*it)->area();
              it=it+1;
            }
            return a;
        }

        double perimeter() const {
            // return sum of all containing shapes perimeter.
            double a=0;
            std::vector<Shape *>::const_iterator it = _shapes.begin();
            std::vector<Shape *>::const_iterator it2 = _shapes.end();
            while (it!=it2) {
              a=a+(*it)->perimeter();
              it=it+1;
            }
            return a;
        }

        std::string info() const {
            // return list of all containing shapes info with wrapped of "CompoundShape {}".
            // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
            std::vector<Shape *>::const_iterator it = _shapes.begin();
            std::vector<Shape *>::const_iterator it2 = _shapes.end();
            std::string str1="Compound Shape {";
            while (it!=it2) {
              if(it==it2-1){
                str1.append((*it)->info());
              }
              else{
                str1.append((*it)->info()+", ");
              }
              it=it+1;
            }
            str1.append("}");
            return str1;
        }

        void addShape(Shape* shape) {
            // add shape into compound shape.
            _shapes.push_back(shape);
        }

        void deleteShapeById(std::string id) {
            // search and delete a shape through id,
            // search all the containing shapes and the tree structure below,
            // if no match of id, throw std::string "Expected delete shape but shape not found"
            //std::cout<<"this is delete id:"<<id<<"\n";
            std::vector<Shape *>::iterator it = _shapes.begin();
            std::vector<Shape *>::iterator it2 = _shapes.end();
            int i=0,tag=0;
            while (it!=it2) {
              if((*it)->color()=="transparent"){
                if((*it)->id()==id){
                  _shapes.erase(_shapes.begin()+i);
                  tag=1;
                  break;
                }
                else{
                  //tag=1;
                  return (*it)->deleteShapeById(id);
                }
              }

              else if((*it)->id()==id){
                _shapes.erase(_shapes.begin()+i);
                tag=1;
                break;
              }
              it=it+1;
              i=i+1;
            }

            if(tag==0){
              throw std::string("Expected delete shape but shape not found");
            }
        }

        Shape* getShapeById(std::string id) {
          // search and return a shape through id,
          // search all the containing shapes and the tree structure below,
          // if no match of id, throw std::string "Expected get shape but shape not found"
          std::vector<Shape *>::iterator it = _shapes.begin();
          std::vector<Shape *>::iterator it2 = _shapes.end();
          int tag1=0;
          while (it!=it2) {
            if((*it)->color()=="transparent"){
              if((*it)->id()==id){
                tag1=1;
                return (*it);
              }
              else{
                //tag1=1;
                return (*it)->getShapeById(id);
              }
            }
            else if((*it)->id()==id){
              tag1=1;
              return (*it);
            }
            it=it+1;
          }

          if(tag1==0){
            throw std::string("Expected get shape but shape not found");
          }
        }

        std::vector<Shape *> _shapes,_shapes2;
};
#endif
