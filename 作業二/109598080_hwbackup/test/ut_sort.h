#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/sort.h"

/*class ShapeSort : public::testing::Test{
protected:
    void Setupelement() {
      std::vector<TwoDimensionalCoordinate*> triangleVector;
      triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
      triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
      triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
      r34 = new Rectangle(3,4);
      e43 = new Ellipse(4,3);
      t345 = new Triangle(triangleVector);
    }
    void Teardown() {
      delete r34;
      delete e43;
      delete t345;
    }
public:
    Shape * r34;
    Shape * e43;
    Shape * t345;
};*/

TEST(ShapeSort, QuickSortAreaAscending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
    //std::cout << "area1 is " << shapes[0]->area() << '\n';
    //std::cout << "area2 is " << shapes[1]->area() << '\n';
    //std::cout << "area3 is " << shapes[2]->area() << '\n';
    ASSERT_EQ(6.000, shapes[0]->area());
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(37.699, (int)(shapes[2]->area()*1000+0.5)/1000.0);
    delete r34;
    delete e43;
    delete t345;
}

TEST(ShapeSort, QuickSortPerimeterAscending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    //std::cout << "perimeter1 is " <<shapes.begin()<<shapes.end() << '\n';
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("perimeter"));
    //std::cout << "perimeter1 is " << shapes[0]->perimeter() << '\n';
    //std::cout << "perimeter2 is " << shapes[1]->perimeter() << '\n';
    //std::cout << "perimeter3 is " << shapes[2]->perimeter() << '\n';
    ASSERT_EQ(12.000, shapes[0]->perimeter());
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(22.850, (int)(shapes[2]->perimeter()*1000+0.5)/1000.0);
    delete r34;
    delete e43;
    delete t345;
}

TEST(ShapeSort, QuickSortAreaDescending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("area"));
    //std::cout << "area1 is " << shapes[0]->area() << '\n';
    //std::cout << "area2 is " << shapes[1]->area() << '\n';
    //std::cout << "area3 is " << shapes[2]->area() << '\n';
    ASSERT_EQ(37.699, (int)(shapes[0]->area()*1000+0.5)/1000.0);
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(6.000, shapes[2]->area());
    delete r34;
    delete e43;
    delete t345;
}

TEST(ShapeSort, QuickSortPerimeterDescending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("perimeter"));
    //std::cout << "perimeter1 is " << shapes[0]->perimeter() << '\n';
    //std::cout << "perimeter2 is " << shapes[1]->perimeter() << '\n';
    //std::cout << "perimeter3 is " << shapes[2]->perimeter() << '\n';
    ASSERT_EQ(22.850, (int)(shapes[0]->perimeter()*1000+0.5)/1000.0);
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(12.000, shapes[2]->perimeter());
    delete r34;
    delete e43;
    delete t345;
}

/*
TEST(ShapeSort, lambdaAreaAscending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end()-1, lambdaAreaAscending);
    ASSERT_EQ(6.000, shapes[0]->area());
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(37.699, (int)(shapes[2]->area()*1000+0.5)/1000.0);
    delete r34;
    delete e43;
    delete t345;
}

TEST(ShapeSort, lambdaPerimeterAscending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end()-1, lambdaPerimeterAscending);
    ASSERT_EQ(12.000, shapes[0]->perimeter());
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(22.850, (int)(shapes[2]->perimeter()*1000+0.5)/1000.0);
    delete r34;
    delete e43;
    delete t345;
}

TEST(ShapeSort, lambdaAreaDescending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end()-1, lambdaAreaDescending);
    ASSERT_EQ(37.699, (int)(shapes[0]->area()*1000+0.5)/1000.0);
    ASSERT_EQ(12.000, shapes[1]->area());
    ASSERT_EQ(6.000, shapes[2]->area());
    delete r34;
    delete e43;
    delete t345;
}

TEST(ShapeSort, lambdaPerimeterDescending) {
    std::vector<TwoDimensionalCoordinate*> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Shape * r34 = new Rectangle(3,4);
    Shape * e43 = new Ellipse(4,3);
    Shape * t345 = new Triangle(triangleVector);
    std::vector<Shape *> shapes;
    shapes.push_back(r34);
    shapes.push_back(e43);
    shapes.push_back(t345);
    quickSort(shapes.begin(), shapes.end()-1, lambdaPerimeterDescending);
    ASSERT_EQ(22.850, (int)(shapes[0]->perimeter()*1000+0.5)/1000.0);
    ASSERT_EQ(14.000, shapes[1]->perimeter());
    ASSERT_EQ(12.000, shapes[2]->perimeter());
    delete r34;
    delete e43;
    delete t345;
}*/
