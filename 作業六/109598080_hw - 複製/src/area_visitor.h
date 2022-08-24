#ifndef AREA_VISITOR
#define AREA_VISITOR
#include "visitor.h"
class AreaVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        // caculate the area of Ellipse.
        // DO NOT use ellipse->area() to get area directly.
        // you may add public function for Ellipse to get it's data members.
        _shapes = ellipse;
    }

    void visit(Triangle* triangle) {
        // caculate the area of Triangle.
        // DO NOT use triangle->area() to get area directly.
        // you may add public function for Triangle to get it's data members.
        _shapes = triangle;
    }

    void visit(Rectangle* rectangle) {
        // caculate the area of Rectangle.
        // DO NOT use rectangle->area() to get area directly.
        // you may add public function for Rectangle to get it's data members.
        _shapes = rectangle;
    }

    void visit(CompoundShape* compoundShape) {
        // caculate the area of CompoundShape.
        // DO NOT use compoundShape->area() to get area directly.
        // you may add public function for CompoundShape to get it's data members.
        _shapes = compoundShape;
    }

    double area() const {
      return _shapes->area();
    }

private:
  Shape * _shapes;
};
#endif
