#include "../src/ellipse.h"
TEST(Shapes, CreateEllipse) {
  Ellipse ellipse(4.000, 3.000);
  //std::cout << "The ellipse area is "<< ellipse.area() << '\n'; //測試用
  //std::cout << "The ellipse perimeter is "<< ellipse.perimeter() << '\n';
  //std::cout << "The ellipse info is "<< ellipse.info() << '\n';
  try {
    Ellipse(0, 1);
    FAIL();
}catch(std::string e) {
    ASSERT_EQ("This is not a ellipse!", e);
}

  ASSERT_NEAR(37.699, ellipse.area(),5);
  ASSERT_NEAR(22.850, ellipse.perimeter(),5);
  ASSERT_EQ("Ellipse (4.000, 3.000)", ellipse.info());
}
