#include "scanner.h"
#include "shape_builder.h"
#include <deque>
#include <vector>
#include <string>
class ShapeParser {
public:
    ShapeParser(std::string input) {
        // initialize a scanner for handling input.
        // initialize a shape builder for handling building shape.
      sc = new Scanner(input);
    }

    void parser() {
        // using Scanner::nextToken() to get all information to determine what to build,
        // and provid the argument the shape needed.
        // use functions in ShapeBuilder to build out the shape.
        // the shape with invalid argument should be ignored (see example bellow).
        //int i=0;
        try{
        while(true){
          _input = sc->nextToken();
          if(_input=="Triangle"){
            if(sc->nextToken()=="("){
              x1=std::stod(sc->nextToken()); //st0d string to double;
            //  printf("%f\n",x1 );
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              y1=std::stod(sc->nextToken());
            //  printf("%f\n", y1);
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              x2=std::stod(sc->nextToken());
            //  printf("%f\n", x2);
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              y2=std::stod(sc->nextToken());
            //  printf("%f\n",y2 );
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              x3=std::stod(sc->nextToken());
              //printf("%f\n", x3);
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              //printf("%d\n",1000 );
              y3=std::stod(sc->nextToken());
              //printf("%f\n", y3);
            }
            else{
              //printf("%d\n",1000141 );
              continue;
            }
            if(sc->nextToken()==")"){
              //printf("%d\n",2000 );
              sb.buildTriangle(x1,y1,x1,y2,x3,y3);
            }
            else{
            //  printf("%d\n",1000141241 );
            continue;
            }
          }
          else if(_input=="Rectangle"){
            if(sc->nextToken()=="("){
              x1=std::stod(sc->nextToken());
            //  printf("%f\n",x1 );
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              y1=std::stod(sc->nextToken());
            //  printf("%f\n", y1);
            }
            if(sc->nextToken()==")"){
              //printf("%d\n",2000 );
              sb.buildRectangle(x1,y1);
            }
            else{
            //  printf("%d\n",1000141241 );
            continue;
            }
          }
          else if(_input=="Ellipse"){
            if(sc->nextToken()=="("){
              x1=std::stod(sc->nextToken());
            //  printf("%f\n",x1 );
            }
            else{
              continue;
            }
            if(sc->nextToken()==","){
              y1=std::stod(sc->nextToken());
            //  printf("%f\n", y1);
            }
            if(sc->nextToken()==")"){
              //printf("%d\n",2000 );
              sb.buildEllipse(x1,y1);
            }
            else{
            //  printf("%d\n",1000141241 );
            continue;
            }
          }
          else if(_input=="CompoundShape"){
            if(sc->nextToken()=="{"){
              sb.buildCompoundShapeBegin();
              i=0;
            }
            else{
              continue;
            }
          }
          else if(_input=="}"){
            sb.buildCompoundShapeEnd();
          }
        }
      }catch(std::string e){}
  }

    std::deque<Shape*> getResult() {
      return sb.getResult();
    }
private:
    Scanner *sc;
    ShapeBuilder sb;
    std::stack<Shape*> _pushdown;
    std::string _input;
    double x1,x2,x3,y1,y2,y3;
    int i=0;
};
