#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/compound_shape.h"
class ShapeSort : public ::testing::Test
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
    //Shape * compoundshapecom = new CompoundShape("7",&shapes);
    //Shape * compoundshapecom2 = new CompoundShape("4",&shapes);
    //Shape * compoundshapecom2 = new CompoundShape("4",&shapes);
};

TEST_F(ShapeSort, test) {
  CompoundShape compoundshape;
  compoundshape.addShape(r34);
  compoundshape.addShape(e43);
  compoundshape.addShape(t345);
  //std::cout<<compoundshape.area()<<"\n";
  //std::cout<<compoundshape.perimeter()<<"\n";
  //std::cout<<compoundshape.info()<<"\n";
  ASSERT_EQ(55.6991,(int)(compoundshape.area()*10000+0.5)/10000.0);
  ASSERT_EQ(48.8496,(int)(compoundshape.perimeter()*10000+0.5)/10000.0);
  ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",compoundshape.info());
  /*std::cout<<compoundshape._shapes[2]->color()<<"\n";
  std::cout<<compoundshape._shapes[0]->perimeter()<<"\n";
  std::cout<<compoundshape._shapes[0]->info()<<"\n";
  std::cout<<compoundshape._shapes[0]->id()<<"\n";
  std::cout<<compoundshape._shapes[0]->color()<<"\n";*/
}

TEST_F(ShapeSort, test1) {
  Shape * compoundshape = new CompoundShape();
  compoundshape->addShape(r34);
  compoundshape->addShape(e43);
  compoundshape->addShape(t345);
  compoundshape->deleteShapeById("1");
  //std::cout<<compoundshape->area()<<"\n";
  //std::cout<<compoundshape->perimeter()<<"\n";
  //std::cout<<compoundshape->info()<<"\n";
  ASSERT_EQ(43.6991,(int)(compoundshape->area()*10000+0.5)/10000.0);
  ASSERT_EQ(34.8496,(int)(compoundshape->perimeter()*10000+0.5)/10000.0);
  ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",compoundshape->info());
}

TEST_F(ShapeSort, test2) {
  try {
    Shape * compoundshape = new CompoundShape();
    compoundshape->addShape(r34);
    compoundshape->addShape(e43);
    compoundshape->addShape(t345);
    compoundshape->deleteShapeById("1");
    compoundshape->deleteShapeById("1");
    FAIL();
}catch(std::string e) {
    ASSERT_EQ("Expected delete shape but shape not found", e);
}

}

TEST_F(ShapeSort, test3) {
  try {
    Shape * compoundshape = new CompoundShape();
    compoundshape->addShape(r34);
    compoundshape->addShape(e43);
    compoundshape->addShape(t345);
    compoundshape->deleteShapeById("1");
    compoundshape->getShapeById("1");
    FAIL();
}catch(std::string e) {
    ASSERT_EQ("Expected get shape but shape not found", e);
}

}

TEST_F(ShapeSort, test4) {
  CompoundShape compoundshape("1",shapes);
  //Shape * compoundshape = new CompoundShape("1",shapes);
  //std::cout<<compoundshape.area()<<"\n";
  //std::cout<<compoundshape.perimeter()<<"\n";
  //std::cout<<compoundshape.info()<<"\n";
  ASSERT_EQ(55.6991,(int)(compoundshape.area()*10000+0.5)/10000.0);
  ASSERT_EQ(48.8496,(int)(compoundshape.perimeter()*10000+0.5)/10000.0);
  ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",compoundshape.info());
  /*std::cout<<compoundshape._shapes[2]->area()<<"\n";
  std::cout<<compoundshape._shapes[2]->perimeter()<<"\n";
  std::cout<<compoundshape._shapes[2]->info()<<"\n";
  std::cout<<compoundshape._shapes[2]->id()<<"\n";
  std::cout<<compoundshape._shapes[2]->color()<<"\n";*/
}

TEST_F(ShapeSort, test5) {
  try {
    Shape * compoundshape = new CompoundShape("7",shapes3);
    compoundshape->addShape(r34);
    compoundshape->addShape(e43);
    compoundshape->addShape(t345);
    std::cout<<compoundshape->area()<<"\n";
    std::cout<<compoundshape->perimeter()<<"\n";
    std::cout<<compoundshape->info()<<"\n";
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("This is not a compound shape!", e);
  }

}

TEST_F(ShapeSort, test7) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes2);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  //std::cout<<compoundshape->info()<<"\n";
  //std::cout<<compoundshape2->info()<<"\n";
  //std::cout<<compoundshape3->info()<<"\n";
  ASSERT_EQ("7",compoundshape3->getShapeById("7")->id());
  //compoundshape3->deleteShapeById("7");
  //compoundshape3->getShapeById("7");
}

TEST_F(ShapeSort, test8) {
  try {
    Shape * compoundshape = new CompoundShape("7",shapes);
    Shape * compoundshape2 = new CompoundShape("8",shapes2);
    Shape * compoundshape3 = new CompoundShape("9",shapes);
    compoundshape2->addShape(compoundshape);
    compoundshape3->addShape(compoundshape2);
    //std::cout<<compoundshape->info()<<"\n";
    //std::cout<<compoundshape2->info()<<"\n";
    //std::cout<<compoundshape3->info()<<"\n";
    compoundshape3->getShapeById("6");
    compoundshape3->deleteShapeById("6");
    compoundshape3->getShapeById("6");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("Expected get shape but shape not found", e);
  }

}

TEST_F(ShapeSort, test9) {
  try {
    Shape * compoundshape = new CompoundShape("7",shapes);
    Shape * compoundshape2 = new CompoundShape("8",shapes2);
    Shape * compoundshape3 = new CompoundShape("9",shapes);
    compoundshape2->addShape(compoundshape);
    compoundshape3->addShape(compoundshape2);
    //std::cout<<compoundshape->info()<<"\n";
    //std::cout<<compoundshape2->info()<<"\n";
    //std::cout<<compoundshape3->info()<<"\n";
    r34->getShapeById("1");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("Only compound shape can get shape!", e);
  }

}
