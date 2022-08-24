#include "../src/compound_shape.h"
#include "../src/visitor.h"
#include "../src/area_visitor.h"
#include "../src/info_visitor.h"
class Testvisitor : public ::testing::Test
{
protected:
    void SetUp() override
    {
      std::vector<TwoDimensionalCoordinate*> triangleVector;
      triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
      triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
      triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
      r34 = new Rectangle("1",3, 4,"red");
      e43 = new Ellipse("2",4, 3,"yellow");
      t345 = new Triangle("3",triangleVector);
      r342 = new Rectangle("4",3, 4,"red");
      e432 = new Ellipse("5",4, 3,"yellow");
      t3452 = new Triangle("6",triangleVector);
      shapes.push_back(r34);
      shapes.push_back(e43);
      shapes.push_back(t345);
      shapes2.push_back(r342);
      shapes2.push_back(e432);
      shapes2.push_back(t3452);
    }

    std::list<Shape *> shapes;
    std::list<Shape *> shapes2;
    std::list<Shape *> shapes3;
    void TearDown() override
    {
      delete r34;
      delete e43;
      delete t345;
      delete r342;
      delete e432;
      delete t3452;
    }

    // Expcted orders
    Shape * r34;
    Shape * e43;
    Shape * t345;
    Shape * r342;
    Shape * e432;
    Shape * t3452;

};

TEST_F(Testvisitor , test) {

}
