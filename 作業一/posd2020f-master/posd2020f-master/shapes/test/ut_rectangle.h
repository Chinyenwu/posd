#include "../src/rectangle.h"

TEST(Shapes, CreateRectangle) {
  Rectangle rectangle(3, 4.5);
  ASSERT_EQ(13.5, rectangle.area());
}
