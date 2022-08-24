#ifndef COMPOUND_SHAPE
#define COMPOUND_SHAPE
#include "shape.h"
#include "shape_iterator.h"
#include "null_iterator.h"
class CompoundShape : public Shape {
public:
        CompoundShape(){

        }

        CompoundShape(std::string id, std::list<Shape*> shapes) {
          this->_id = id;
          _shapes = shapes;
          std::list<Shape *>::iterator it = _shapes.begin();
          std::list<Shape *>::iterator it2 = _shapes.end();
          if(it==it2){
            //throw std::string("This is not a compound shape!");
          }
        }

        Iterator* createIterator() const {
          Iterator * shapeiterator = new ShapeIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
          return shapeiterator;
        }


        double area() const {
            // return sum of all containing shapes area.
            double a=0;
            std::list<Shape *>::const_iterator it = _shapes.begin();
            std::list<Shape *>::const_iterator it2 = _shapes.end();
            while (it!=it2) {
              a=a+(*it)->area();
              it++;
            }
            return a;
        }

        double perimeter() const {
            // return sum of all containing shapes perimeter.
            double a=0;
            std::list<Shape *>::const_iterator it = _shapes.begin();
            std::list<Shape *>::const_iterator it2 = _shapes.end();
            while (it!=it2) {
              a=a+(*it)->perimeter();
              it++;
            }
            return a;
        }

        std::string info() const {
            // return list of all containing shapes info with wrapped of "CompoundShape {}".
            // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
            std::list<Shape *>::const_iterator it = _shapes.begin();
            std::list<Shape *>::const_iterator it2 = _shapes.end();
            std::list<Shape *>::const_iterator itpre;
            std::string str1="Compound Shape {";
            while (it!=it2) {
              str1.append((*it)->info());
              itpre = std::next(it,1);
              if(itpre!=it2){
                str1.append(", ");
              }
              it++;
            }
            str1.append("}");
            return str1;
        }

        std::string type() const{
            return "Compound Shape";
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
            std::list<Shape *>::iterator it = _shapes.begin();
            std::list<Shape *>::iterator it2 = _shapes.end();
            int i=0,tag=0;
            try {
              (*it)->getShapeById(id);
              }catch(std::string e) {
                if(e=="Expected get shape but shape not found"){
                  throw std::string("Expected delete shape but shape not found");
                }
              }

            while (it!=it2) {
              if((*it)->id()==id){
                _shapes.erase(it);
                tag=1;
                break;
              }
              else{
                try{
                  return (*it)->deleteShapeById(id);
                }catch(std::string e){}
              }

              it++;
              i=i+1;
            }

            if(tag==0){
              throw std::string("Expected delete shape but shape not found");
            }
        }

        Shape* getShapeById(std::string id) const{
          // search and return a shape through id,
          // search all the containing shapes and the tree structure below,
          // if no match of id, throw std::string "Expected get shape but shape not found"
          std::list<Shape *>::const_iterator it = _shapes.begin();
          std::list<Shape *>::const_iterator it2 = _shapes.end();
          int tag1=0;
          while (it!=it2) {
            if((*it)->id()==id){
              tag1=1;
              return (*it);
            }
            else{
              try {
                Shape * mbox;
                mbox = (*it)->getShapeById(id);
                if(mbox->id()==id){
                  tag1=1;
                  return (mbox);
                }
                }catch(std::string e) {}
            }
            it++;
          }

          if(tag1==0){
            throw std::string("Expected get shape but shape not found");
          }
        }

        void accept(Visitor* visitor){
          visitor->visit(this);
        }

        std::list<Shape *> shapearea(){
          return _shapes;
        }
        std::list<Shape *> _shapes,_shapes2;

};
#endif
