#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/sort.h"

class ShapeSort : public ::testing::Test
{
protected:
    void SetUp() override
    {
      std::vector<TwoDimensionalCoordinate*> triangleVector;
      triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
      triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
      triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
      r34 = new Rectangle(3,4);
      e43 = new Ellipse(4,3);
      t345 = new Triangle(triangleVector);
      shapes.push_back(r34);
      shapes.push_back(e43);
      shapes.push_back(t345);
    }

    std::vector<Shape *> shapes;

    void TearDown() override
    {
      delete r34;
      delete e43;
      delete t345;
    }

    // Expcted orders
    Shape * r34;
    Shape * e43;
    Shape * t345;
};



TEST_F(ShapeSort, QuickSortAreaAscending) {
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
    //std::cout << "area1 is " << shapes[0]->area() << '\n';
    //std::cout << "area2 is " << shapes[1]->area() << '\n';
    //std::cout << "area3 is " << shapes[2]->area() << '\n';
    ASSERT_EQ(6.000, shapes[0]->area());
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(37.699, (int)(shapes[2]->area()*1000+0.5)/1000.0);
}

TEST_F(ShapeSort, QuickSortPerimeterAscending) {
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("perimeter"));
    //std::cout << "perimeter1 is " << shapes[0]->perimeter() << '\n';
    //std::cout << "perimeter2 is " << shapes[1]->perimeter() << '\n';
    //std::cout << "perimeter3 is " << shapes[2]->perimeter() << '\n';
    ASSERT_EQ(12.000, shapes[0]->perimeter());
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(22.850, (int)(shapes[2]->perimeter()*1000+0.5)/1000.0);
}

TEST_F(ShapeSort, QuickSortAreaDescending) {
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("area"));
    //std::cout << "area1 is " << shapes[0]->area() << '\n';
    //std::cout << "area2 is " << shapes[1]->area() << '\n';
    //std::cout << "area3 is " << shapes[2]->area() << '\n';
    ASSERT_EQ(37.699, (int)(shapes[0]->area()*1000+0.5)/1000.0);
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(6.000, shapes[2]->area());
}

TEST_F(ShapeSort, QuickSortPerimeterDescending) {
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("perimeter"));
    //std::cout << "perimeter1 is " << shapes[0]->perimeter() << '\n';
    //std::cout << "perimeter2 is " << shapes[1]->perimeter() << '\n';
    //std::cout << "perimeter3 is " << shapes[2]->perimeter() << '\n';
    ASSERT_EQ(22.850, (int)(shapes[0]->perimeter()*1000+0.5)/1000.0);
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(12.000, shapes[2]->perimeter());
}

TEST_F(ShapeSort, QuickSortAreaAscending1) {
    quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);
    //std::cout << "area1 is " << shapes[0]->area() << '\n';
    //std::cout << "area2 is " << shapes[1]->area() << '\n';
    //std::cout << "area3 is " << shapes[2]->area() << '\n';
    ASSERT_EQ(6.000, shapes[0]->area());
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(37.699, (int)(shapes[2]->area()*1000+0.5)/1000.0);
}

TEST_F(ShapeSort, QuickSortPerimeterAscending1) {
    quickSort(shapes.begin(), shapes.end(), perimeterAscendingCompare);
    //std::cout << "perimeter1 is " << shapes[0]->perimeter() << '\n';
    //std::cout << "perimeter2 is " << shapes[1]->perimeter() << '\n';
    //std::cout << "perimeter3 is " << shapes[2]->perimeter() << '\n';
    ASSERT_EQ(12.000, shapes[0]->perimeter());
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(22.850, (int)(shapes[2]->perimeter()*1000+0.5)/1000.0);
}

TEST_F(ShapeSort, QuickSortAreaDescending1) {
    quickSort(shapes.begin(), shapes.end(), areaDescendingCompare);
    //std::cout << "area1 is " << shapes[0]->area() << '\n';
    //std::cout << "area2 is " << shapes[1]->area() << '\n';
    //std::cout << "area3 is " << shapes[2]->area() << '\n';
    ASSERT_EQ(37.699, (int)(shapes[0]->area()*1000+0.5)/1000.0);
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(6.000, shapes[2]->area());
}

TEST_F(ShapeSort, QuickSortPerimeterDescending1) {
    quickSort(shapes.begin(), shapes.end(), perimeterDescendingCompare);
    //std::cout << "perimeter1 is " << shapes[0]->perimeter() << '\n';
    //std::cout << "perimeter2 is " << shapes[1]->perimeter() << '\n';
    //std::cout << "perimeter3 is " << shapes[2]->perimeter() << '\n';
    ASSERT_EQ(22.850, (int)(shapes[0]->perimeter()*1000+0.5)/1000.0);
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(12.000, shapes[2]->perimeter());
}
