#include "../src/utility.h"
#include "../src/compound_shape.h"
#include "../src/shape_iterator.h"
#include "../src/null_iterator.h"
class Testutility : public ::testing::Test
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

TEST_F(Testutility, testgetidothershape) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  //filterShape(compoundshape, AreaFilter(10, 5));
  try{
    getShapeById(r34,"1");
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can get shape!", e);
  }
  try{
    getShapeById(e43,"2");
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can get shape!", e);
  }
  try{
    getShapeById(t345,"3");
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can get shape!", e);
  }
}

TEST_F(Testutility, testfilterothershape) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  //filterShape(compoundshape, AreaFilter(10, 5));
  try{
    filterShape(r34,  ColorFilter("red"));
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can filter shape!", e);
  }
  try{
    filterShape(e43,  AreaFilter(20, 5));
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can filter shape!", e);
  }
  try{
    filterShape(t345, PerimeterFilter(20, 5));
  }catch(std::string e){
    ASSERT_EQ("Only compound shape can filter shape!", e);
  }
}

TEST_F(Testutility, testfindcompoundshapeexcept) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  //filterShape(compoundshape, AreaFilter(10, 5));
  try{
    getShapeById(compoundshape,"4");
  }catch(std::string e){
    ASSERT_EQ("Expected get shape but shape not found", e);
  }
}

TEST_F(Testutility, testfindcompoundshape2) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  //filterShape(compoundshape, AreaFilter(10, 5));
  ASSERT_EQ("3", getShapeById(compoundshape,"3")->id());
}

TEST_F(Testutility, testfiltershapesarea) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  ASSERT_EQ(4, filterShape(compoundshape2, AreaFilter(20, 5)).size());
}

TEST_F(Testutility, testfiltershapesperimeter) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  ASSERT_EQ(4, filterShape(compoundshape2, PerimeterFilter(20, 5)).size());
}

TEST_F(Testutility, testfiltershapescolor) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  ASSERT_EQ(2, filterShape(compoundshape2, ColorFilter("red")).size());
}

TEST_F(Testutility, testfiltershapestype) {
  Shape * compoundshape = new CompoundShape("7",shapes);
  Shape * compoundshape2 = new CompoundShape("8",shapes2);
  Shape * compoundshape3 = new CompoundShape("9",shapes);
  compoundshape2->addShape(compoundshape);
  compoundshape3->addShape(compoundshape2);
  ASSERT_EQ(2, filterShape(compoundshape2, TypeFilter("Ellipse")).size());
}
