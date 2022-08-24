#ifndef INFO_VISITOR
#define INFO_VISITOR
#include "visitor.h"
class InfoVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        // caculate the area of Ellipse.
        // DO NOT use ellipse->area() to get area directly.
        // you may add public function for Ellipse to get it's data members.
        char str[80];
        sprintf(str, "Ellipse (%.3f, %.3f)", ellipse->major(),ellipse->minor());
        _info = str;
    }

    void visit(Triangle* triangle) {
        // caculate the area of Triangle.
        // DO NOT use triangle->area() to get area directly.
        // you may add public function for Triangle to get it's data members.
        char str[100];
        sprintf(str, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",triangle->xx1(),triangle->yy1(),triangle->xx2(),triangle->yy2(),triangle->xx3(),triangle->yy3());
        _info = str;
    }

    void visit(Rectangle* rectangle) {
        // caculate the area of Rectangle.
        // DO NOT use rectangle->area() to get area directly.
        // you may add public function for Rectangle to get it's data members.
        char str[80];
        sprintf(str, "Rectangle (%.3f, %.3f)", rectangle->len(),rectangle->wid());
        _info = str;
    }

    void visit(CompoundShape* compoundShape) {
        // caculate the area of CompoundShape.
        // DO NOT use compoundShape->area() to get area directly.
        // you may add public function for CompoundShape to get it's data members.
        std::string str1="Compound Shape {";
        Iterator * it = compoundShape->createIterator();
        InfoVisitor * vv = new InfoVisitor();
        it->currentItem()->accept(vv);
        str1 = str1 + vv->info();
        it->next();
        while(it->isDone()!=1){
          InfoVisitor * v = new InfoVisitor();
          it->currentItem()->accept(v);
          str1 = str1 +", " +v->info();
          it->next();
        }
        _info = str1+"}";
    }

    std::string info() const {
      return _info;
    }

private:
  std::string _info;
};
#endif
