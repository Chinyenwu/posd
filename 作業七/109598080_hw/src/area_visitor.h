#ifndef AREA_VISITOR
#define AREA_VISITOR
#include "visitor.h"
class AreaVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        // caculate the area of Ellipse.
        // DO NOT use ellipse->area() to get area directly.
        // you may add public function for Ellipse to get it's data members.
        _area = M_PI*ellipse->major()*ellipse->minor() ;
    }

    void visit(Triangle* triangle) {
        // caculate the area of Triangle.
        // DO NOT use triangle->area() to get area directly.
        // you may add public function for Triangle to get it's data members.
        double s = (triangle->xx() + triangle->yy() + triangle->zz()) / 2;
        _area = sqrt(s * (s - triangle->xx()) * (s - triangle->yy()) * (s - triangle->zz()));
    }

    void visit(Rectangle* rectangle) {
        // caculate the area of Rectangle.
        // DO NOT use rectangle->area() to get area directly.
        // you may add public function for Rectangle to get it's data members.
        _area = rectangle->len()*rectangle->wid() ;
    }

    void visit(CompoundShape* compoundShape) {
        // caculate the area of CompoundShape.
        // DO NOT use compoundShape->area() to get area directly.
        // you may add public function for CompoundShape to get it's data members.
        Iterator * it = compoundShape->createIterator();
        while(it->isDone()!=1){
          AreaVisitor * v = new AreaVisitor();
          it->currentItem()->accept(v);
          _area = _area + v->area();
          it->next();
        }
    }

    double area() const {
        return _area;
    }

private:
  double _area=0;

};
#endif
