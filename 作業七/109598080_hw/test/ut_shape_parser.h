#include "../src/shape_parser.h"

TEST(ShapeParserTest, parser_triangle) {
    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}

TEST(ShapeParserTest, parser_rectangle) {

    ShapeParser sp("Rectangle (3.000, 4.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
}

TEST(ShapeParserTest, parser_ellipse) {

    ShapeParser sp("Ellipse (4.200, 3.700)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[0]->info());
}

TEST(ShapeParserTest, parser_multi_simple_shapes) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
}

TEST(ShapeParserTest, parser_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
}

TEST(ShapeParserTest, parser_empty) {
    //ShapeParser sp("Ellipse (4.200, 3.700)");
    ShapeParser sp("CompoundShape {}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    EXPECT_EQ("Compound Shape {}", results[0]->info());
}


TEST(ShapeParserTest, parser_compoundshape_multi_simple_shapes) {

    ShapeParser sp("CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {}}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {}}", results[0]->info());
}

TEST(ShapeParserTest, parser_compoundshape_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {}}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {}}", results[0]->info());
}

TEST(ShapeParserTest, parser_compoundshape_multi_simple_shapesL3) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000),CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}}}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(4, results.size());
    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}}", results[3]->info());
}


TEST(ShapeParserTest, parser_compoundshape_multi_simple_shapesL3_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000),CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}}}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(4, results.size());
    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}}", results[3]->info());
}
