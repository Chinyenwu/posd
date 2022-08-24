#include "../src/shape_builder.h"

TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}

TEST(ShapeBuilderTest, build_Rectangle) {
    ShapeBuilder sb;
    sb.buildRectangle(3,4);
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
}

TEST(ShapeBuilderTest, build_Ellipse) {
    ShapeBuilder sb;
    sb.buildEllipse(4,3);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Ellipse (4.000, 3.000)", results[0]->info());
}

TEST(ShapeBuilderTest, build_mutiple) {
    ShapeBuilder sb;
    sb.buildEllipse(4,3);
    sb.buildRectangle(3,4);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(3, results.size());
    ASSERT_EQ("Ellipse (4.000, 3.000)", results[0]->info());
    ASSERT_EQ("Rectangle (3.000, 4.000)", results[1]->info());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
}

TEST(ShapeBuilderTest, build_empty_CompoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {}", results[0]->info());
}

TEST(ShapeBuilderTest, build_empty_CompoundShape3) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}}", results[0]->info());
}

TEST(ShapeBuilderTest, build_empty_CompoundShape2) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000)}", results[0]->info());
}

TEST(ShapeBuilderTest, build_CompoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(4, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results[0]->info());
}

TEST(ShapeBuilderTest, build_CompoundShape2) {
    ShapeBuilder sb;
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(4, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}", results[3]->info());
}

TEST(ShapeBuilderTest, build_CompoundShape3) {
    ShapeBuilder sb;
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(4, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}}", results[3]->info());
}

TEST(ShapeBuilderTest, build_CompoundShape4) {
    ShapeBuilder sb;
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3,4);
    sb.buildEllipse(4,3);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(5, results.size());
    ASSERT_EQ("Compound Shape {}", results[4]->info());
}
