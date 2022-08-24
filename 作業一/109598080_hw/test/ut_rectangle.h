#include "../src/rectangle.h"
TEST(Shapes, CreateRectangle) {
  Rectangle rectangle(3, 4);
  //std::cout << "The rectangle area is "<< rectangle.area() << '\n'; //測試用
  //std::cout << "The rectangle perimeter is "<< rectangle.perimeter() << '\n';
  //std::cout << "The rectangle info is "<< rectangle.info() << '\n';
  try {
    Rectangle(0, 1); 
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("This is not a rectangle!", e);
  }

  ASSERT_EQ(12.000, rectangle.area());
  ASSERT_EQ(14.000, rectangle.perimeter());
  ASSERT_EQ("Rectangle (3.000, 4.000)", rectangle.info());

}
