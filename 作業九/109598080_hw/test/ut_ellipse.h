#include "../src/ellipse.h"
TEST(Shapes, CreateEllipse) {
  Ellipse ellipse(4.000, 3.000);
  //std::cout << "The ellipse area is "<< ellipse.area() << '\n'; //測試用
  //std::cout << "The ellipse perimeter is "<< ellipse.perimeter() << '\n';
  //std::cout << "The ellipse info is "<< ellipse.info() << '\n';
  try {
    Ellipse ellipseerror(0, -1);
    FAIL();
}catch(std::string e) {
    ASSERT_EQ("This is not an ellipse!", e);
}

try {
  Ellipse ellipseerror2(3, 4);
  FAIL();
}catch(std::string e) {
  ASSERT_EQ("This is not an ellipse!", e);
}
  ASSERT_EQ(37.699, (int)(ellipse.area()*1000+0.5)/1000.0);
  ASSERT_EQ(22.850, (int)(ellipse.perimeter()*1000+0.5)/1000.0);
  ASSERT_EQ("Ellipse (4.000, 3.000)", ellipse.info());
}
