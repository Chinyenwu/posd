#include <gtest/gtest.h>
#include "ut_rectangle.h"
#include "ut_ellipse.h"
#include "ut_triangle.h"
int main(int argc, char ** argv)
{
  //std::cout << "test" << '\n'; //test
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
