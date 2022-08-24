#include "../src/filter.h"
#include "../src/shape_filter.h"
#include "../src/shape_setter.h"
class FilterTest : public ::testing::Test
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

TEST_F(FilterTest, PerimeterFilter)
{

  Filter* perimeterfilter1 = new ShapeFilter([](Shape* shape) {return shape->perimeter() <= 30;});
  Filter* perimeterfilter2 = new ShapeFilter([](Shape* shape) {return shape->perimeter() >= 15;});
  //Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "yellow";});

  perimeterfilter1->setNext(perimeterfilter2);
  std::list<Shape*> results = perimeterfilter1->push(shapes);
  ASSERT_EQ(1, results.size());
  //std::cout<<results.size()<<"\n";
}

TEST_F(FilterTest, AreaFilter)
{

  Filter* areafilter1 = new ShapeFilter([](Shape* shape) {return shape->area() <= 30;});
  Filter* areafilter2 = new ShapeFilter([](Shape* shape) {return shape->area() >= 10;});

  areafilter1->setNext(areafilter2);
  std::list<Shape*> results = areafilter1->push(shapes);
  ASSERT_EQ(1, results.size());
  //std::cout<<results.size()<<"\n";
}

TEST_F(FilterTest, PerimeterAreaFilter)
{

  Filter* perimeterfilter1 = new ShapeFilter([](Shape* shape) {return shape->perimeter() <= 30;});
  Filter* areafilter2 = new ShapeFilter([](Shape* shape) {return shape->area() >= 15;});

  perimeterfilter1->setNext(areafilter2);
  std::list<Shape*> results = perimeterfilter1->push(shapes);
  ASSERT_EQ(1, results.size());
  //std::cout<<results.size()<<"\n";
}

TEST_F(FilterTest, PerimeterAreacolorFilter)
{

  Filter* perimeterfilter1 = new ShapeFilter([](Shape* shape) {return shape->perimeter() <= 30;});
  Filter* areafilter2 = new ShapeFilter([](Shape* shape) {return shape->area() >= 15;});
  Filter* colorFilter = new ShapeFilter([](Shape* shape) {return shape->color() == "yellow";});
  perimeterfilter1->setNext(areafilter2)->setNext(colorFilter);
  std::list<Shape*> results = perimeterfilter1->push(shapes);
  ASSERT_EQ(1, results.size());
  //std::cout<<results.size()<<"\n";
}

TEST_F(FilterTest, AreaSetter1)
{
  Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() < 30;});
  Filter* perimeterfilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() <= 30;});
  Filter* colorSetter = new ShapeSetter([](Shape* shape) {return shape->setColor("black");});
  areaFilter->setNext(perimeterfilter)->setNext(colorSetter);
  std::list<Shape*> results = areaFilter->push(shapes);
  ASSERT_EQ(2, results.size());
  ASSERT_EQ("black", r34->color());
  //std::cout<<results.size()<<"\n";
}

TEST_F(FilterTest, AreaSetter2)
{
  Filter* areaFilter = new ShapeFilter([](Shape* shape) {return shape->area() < 30;});
  Filter* perimeterfilter = new ShapeFilter([](Shape* shape) {return shape->perimeter() > 150;});
  Filter* colorSetter = new ShapeSetter([](Shape* shape) {return shape->setColor("black");});
  areaFilter->setNext(perimeterfilter)->setNext(colorSetter);
  std::list<Shape*> results = areaFilter->push(shapes);
  ASSERT_EQ(0, results.size());
  //std::cout<<results.size()<<"\n";
}
