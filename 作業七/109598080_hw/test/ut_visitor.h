#include "../src/compound_shape.h"
#include "../src/visitor.h"
#include "../src/area_visitor.h"
#include "../src/info_visitor.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
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
  AreaVisitor * vr34 = new AreaVisitor();
  r34->accept(vr34);
  ASSERT_EQ(12, vr34->area());
  AreaVisitor * ve43 = new AreaVisitor();
  e43->accept(ve43);
  ASSERT_NEAR(37.699, ve43->area(),6);
  AreaVisitor * vt345 = new AreaVisitor();
  t345->accept(vt345);
  ASSERT_EQ(6, vt345->area());
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes2);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  AreaVisitor * vcompoundshape = new AreaVisitor();
  compoundshape->accept(vcompoundshape);
  ASSERT_NEAR(55.699, vcompoundshape->area(),6);
  AreaVisitor * vcompoundshape3 = new AreaVisitor();
  compoundshape3->accept(vcompoundshape3);
  ASSERT_NEAR(167.097, vcompoundshape3->area(),6);
}

TEST_F(Testvisitor , test2) {
  InfoVisitor * vr34 = new InfoVisitor();
  r34->accept(vr34);
  ASSERT_EQ("Rectangle (3.000, 4.000)", vr34->info());
  InfoVisitor * ve43 = new InfoVisitor();
  e43->accept(ve43);
  ASSERT_EQ("Ellipse (4.000, 3.000)", ve43->info());
  InfoVisitor * vt345 = new InfoVisitor();
  t345->accept(vt345);
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", vt345->info());
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes2);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  InfoVisitor * vcompoundshape = new InfoVisitor();
  compoundshape->accept(vcompoundshape);
  ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",vcompoundshape->info());
  InfoVisitor * vcompoundshape3 = new InfoVisitor();
  compoundshape3->accept(vcompoundshape3);
  ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}}}",vcompoundshape3->info());
}
