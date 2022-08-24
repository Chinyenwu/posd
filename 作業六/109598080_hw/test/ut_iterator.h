#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/shape_iterator.h"
#include "../src/null_iterator.h"
class TestIterator : public ::testing::Test
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
TEST_F(TestIterator, NextIterator) {

    Shape * compoundshape = new CompoundShape("7",shapes);
    Shape * compoundshape2 = new CompoundShape("8",shapes2);
    Shape * compoundshape3 = new CompoundShape("9",shapes);
    compoundshape2->addShape(compoundshape);
    compoundshape3->addShape(compoundshape2);
    /*std::cout<<compoundshape->info()<<"\n";
    std::cout<<compoundshape2->info()<<"\n";*/
    //std::cout<<compoundshape3->info()<<"\n";
    Iterator * it = compoundshape->createIterator();
    ASSERT_NEAR(12,it->currentItem()->area(),6 );
    it->next();
    ASSERT_NEAR(37.699,it->currentItem()->area(),6 );
    it->next();
    ASSERT_NEAR(6,it->currentItem()->area(),6 );
    it->next();
    //std::cout<<it->currentItem()->area()<<"\n";
}

TEST_F(TestIterator, FirstIterator) {

    Shape * compoundshape = new CompoundShape("7",shapes);
    Shape * compoundshape2 = new CompoundShape("8",shapes2);
    Shape * compoundshape3 = new CompoundShape("9",shapes);
    compoundshape2->addShape(compoundshape);
    compoundshape3->addShape(compoundshape2);
    /*std::cout<<compoundshape->info()<<"\n";
    std::cout<<compoundshape2->info()<<"\n";*/
    //std::cout<<compoundshape3->info()<<"\n";
    Iterator * it = compoundshape3->createIterator();
    ASSERT_NEAR(12,it->currentItem()->area(),6 );
}

TEST_F(TestIterator, IsDoneIterator) {

    Shape * compoundshape = new CompoundShape("7",shapes);
    Shape * compoundshape2 = new CompoundShape("8",shapes2);
    Shape * compoundshape3 = new CompoundShape("9",shapes);
    compoundshape2->addShape(compoundshape);
    compoundshape3->addShape(compoundshape2);
    /*std::cout<<compoundshape->info()<<"\n";
    std::cout<<compoundshape2->info()<<"\n";*/
    //std::cout<<compoundshape3->info()<<"\n";
    Iterator * it = compoundshape->createIterator();
    it->next();
    it->next();
    it->next();
    ASSERT_NEAR(1,it->isDone(),6 );
}

TEST_F(TestIterator, ExceptIteratornext) {

    Shape * compoundshape = new CompoundShape("7",shapes);
    Shape * compoundshape2 = new CompoundShape("8",shapes2);
    Shape * compoundshape3 = new CompoundShape("9",shapes);
    compoundshape2->addShape(compoundshape);
    compoundshape3->addShape(compoundshape2);
    try{
      Iterator * it = compoundshape->createIterator();
      it->next();
      it->next();
      it->next();
      it->next();
    }
    catch(std::string e){
      ASSERT_EQ("Moving past the end!", e);
    }
}

TEST_F(TestIterator, OtherShapeIteratorisDone) {
    Iterator * it = r34->createIterator();
    ASSERT_NEAR(1,it->isDone(),6 );
    Iterator * it1 = e43->createIterator();
    ASSERT_NEAR(1,it1->isDone(),6 );
    Iterator * it2 = t345->createIterator();
    ASSERT_NEAR(1,it2->isDone(),6 );
}

TEST_F(TestIterator, OtherShapeIteratorfirst) {
  try{
    Iterator * it = r34->createIterator();
    it->first();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
  try{
    Iterator * it1 = e43->createIterator();
    it1->first();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
  try{
    Iterator * it2 = t345->createIterator();
    it2->first();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
}

TEST_F(TestIterator, OtherShapeIteratorcurrent) {
  try{
    Iterator * it = r34->createIterator();
    it->currentItem();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
  try{
    Iterator * it1 = e43->createIterator();
    it1->currentItem();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
  try{
    Iterator * it2 = t345->createIterator();
    it2->currentItem();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
}

TEST_F(TestIterator, OtherShapeIteratornext) {
  try{
    Iterator * it = r34->createIterator();
    it->next();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
  try{
    Iterator * it1 = e43->createIterator();
    it1->next();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
  try{
    Iterator * it2 = t345->createIterator();
    it2->next();
  }
  catch(std::string e){
    ASSERT_EQ("No child member!", e);
  }
}
