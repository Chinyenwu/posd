#include "../src/terminal.h"

TEST(TerminalTest, ReadFile)
{
  Terminal terminal("Rectangle (2, 2) Ellipse (4, 3) Triangle ([0,0], [3,0], [0,4]) area inc");
  ASSERT_EQ("4.000\n6.000\n37.699", terminal.showResult());
}

TEST(TerminalTest1, ReadFile)
{
  Terminal terminal("Rectangle (2, 2) Ellipse (4, 3) Triangle ([0,0], [3,0], [0,4]) area dec");
  ASSERT_EQ("37.699\n6.000\n4.000", terminal.showResult());
}

TEST(TerminalTest2, ReadFile)
{
  Terminal terminal("Rectangle (2, 2) Ellipse (4, 3) Triangle ([0,0], [3,0], [0,4]) perimeter inc");
  ASSERT_EQ("8.000\n12.000\n22.850", terminal.showResult());
}

TEST(TerminalTest3, ReadFile)
{
  Terminal terminal("Rectangle (2, 2)   Ellipse (4, 3)   Triangle ([0,0], [3,0], [0,4]) perimeter dec");
  ASSERT_EQ("22.850\n12.000\n8.000", terminal.showResult());
}

TEST(TerminalTest4, ReadFile)
{
  Terminal terminal("Rectangle (2, 2)   Ellipse (0, 3)   Triangle ([0,0], [3,0], [0,4]) perimeter dec");
  ASSERT_EQ("12.000\n8.000", terminal.showResult());
}
TEST(TerminalTest5, ReadFile)
{
  try {
    Terminal terminal(" perimeter dec");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("invalid input", e);
  }
}

TEST(TerminalTest6, ReadFile)
{
  try {
    Terminal terminal("Rectangle (2, 2)   Ellipse (4, 3)   Triangle ([0,0], [3,0], [0,4]) perimeter");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest7, ReadFile)
{
  try {
    Terminal terminal("Rectangle (2, 2)   Ellipse (4, 3)   Triangle ([0,0], [3,0], [0,4]) dec");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest8, ReadFile)
{
  try {
    Terminal terminal("Rectangle (2, 2) Ellipse (4, 3) Triangle ([0,0], [3,0], [0,4])");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest9, ReadFile)
{
  Terminal terminal("Rectangle   (  2, 2  )   Ellipse !(4, 3)   Triangle ([0,0], [3,0], [0,4]) perimeter dec");
  ASSERT_EQ("12.000\n8.000", terminal.showResult());
}
TEST(TerminalTest12, ReadFile)
{
  try {
    Terminal terminal("Rectangle(2,2) Ellipse(4, 3) Triangle([0,0], [3,0], [4,0]) perimeter inc");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("invalid input", e);
  }
}
TEST(TerminalTest13, ReadFile)
{
  try {
    Terminal terminal("Rectangle (0,0) Rectangle (0, 0) Triangle ([0,0], [0,0], [4,0]) perimeter inc");
    FAIL();
  }catch(std::string e) {
    ASSERT_EQ("invalid input", e);
  }
}
