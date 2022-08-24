#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
TEST(Shapes, CreateTriangle) {
  std::vector<TwoDimensionalCoordinate*> triangleVector;
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
  triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));


  Triangle triangle(triangleVector);
  //std::cout << "The triangle area is "<< triangle.area() << '\n'; //測試用
  //std::cout << "The triangle perimeter is "<< triangle.perimeter() << '\n';
  //std::cout << "The triangle info is "<< triangle.info() << '\n';
  try {
    std::vector<TwoDimensionalCoordinate*> triangleVectorerror;
    triangleVectorerror.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVectorerror.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVectorerror);
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("This is not a triangle!", e);
  }

  ASSERT_EQ(6.000, triangle.area());
  ASSERT_EQ(12.000, triangle.perimeter());
  ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}
