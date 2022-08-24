#ifndef SHAPE_BUILDER
#define SHAPE_BUILDER
#include "compound_shape.h"
#include "two_dimensional_coordinate.h"
#include <deque>
#include <stack>
class ShapeBuilder {
public:
    ShapeBuilder() {}

    void buildRectangle(double length, double width) {
        // build a rectangle with an unique id and push in a std::stack.
        id = id+1;
        std::string ids = std::to_string(id);
        Shape * r = new Rectangle(ids,length, width);
        _pushdown.push(r);

    }

    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        // build a ellipse with an unique id and push in a std::stack.
        id = id+1;
        std::string ids = std::to_string(id);
        Shape * e = new Ellipse(ids,semiMajorAxes, semiMinorAxes);
        _pushdown.push(e);
    }

    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        // build a triangle with an unique id and push in a std::stack.
        id = id+1;
        std::string ids = std::to_string(id);
        std::vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(x1, y1));
        triangleVector.push_back(new TwoDimensionalCoordinate(x2, y2));
        triangleVector.push_back(new TwoDimensionalCoordinate(x3, y3));
        Shape * t = new Triangle(ids,triangleVector);
        _pushdown.push(t);
    }

    void buildCompoundShapeBegin() {
        // for notifing beginning of a Compound Shape.
        /*Shape * ms = new CompoundShape();
       _pushdown.push(ms);*/
       id = id+1;
       std::string ids = std::to_string(id);
       std::list<Shape *> _shapes;
       Shape * cs = new CompoundShape(ids,_shapes);
       _pushdown.push(cs);
       begin.push_back(cs);
    }

    void buildCompoundShapeEnd() {
        // for notifing ending of a Compound Shape.
        //try{

        while (!dynamic_cast<CompoundShape*>(_pushdown.top())||(dynamic_cast<CompoundShape*>(_pushdown.top()) && !_pushdown.top()->createIterator()->isDone())){
          v.push_back(_pushdown.top());
          _pushdown.pop();
        }

        for (auto it=v.rbegin();it!=v.rend();it++){
          _pushdown.top()->addShape(*it);
        }
        v.clear();
        begin.pop_back();
        if(!begin.empty()){
          v.push_back(_pushdown.top());
          _pushdown.pop();
        }
      //}catch(std::string e){}
    }

    std::deque<Shape*> getResult() {
        // return result.
        std::deque<Shape *> result;
          while(!_pushdown.empty()){
            result.push_back(_pushdown.top());
            _pushdown.pop();
          }
          return std::deque<Shape*>(result.rbegin(),result.rend());
    }

private:
    std::stack<Shape *> _pushdown;
    std::deque<Shape *> v;
    std::deque<Shape *> begin;
    int id = 0;
};

#endif
