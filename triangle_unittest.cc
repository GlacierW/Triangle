#include "triangle.h"
#include <gtest/gtest.h>

TEST( TriangleTest, NegativeEdge ) {
	// one negative edge
	EXPECT_EQ( get_triangle_type(-1, 1, 1), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(1, -1, 1), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(1, 1, -1), TYPE_TRIANGLE_INVALID );
	
	// two negative edges 
	EXPECT_EQ( get_triangle_type(-1, -1, 1), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(1, -1, -1), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(-1, 1, -1), TYPE_TRIANGLE_INVALID );
	
	// all negative edges 
	EXPECT_EQ( get_triangle_type(-1, -1, -1), TYPE_TRIANGLE_INVALID );
}

TEST( TriangleTest, NotTriangle ) {
	EXPECT_EQ( get_triangle_type(1, 2, 3), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(1, 3, 2), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(2, 1, 3), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(3, 1, 2), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(3, 2, 1), TYPE_TRIANGLE_INVALID );
	EXPECT_EQ( get_triangle_type(2, 3, 1), TYPE_TRIANGLE_INVALID );
}

TEST( TriangleTest, EquilateralTriange ) {
	EXPECT_EQ( get_triangle_type(10, 10, 10), TYPE_TRIANGLE_EQUILATERAL );
}

TEST( TriangleTest, IsoscelesTriange ) {
	EXPECT_EQ( get_triangle_type(10, 100, 100), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(100, 10, 100), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(100, 100, 10), TYPE_TRIANGLE_ISOSCELES );
}

TEST( TriangleTest, ScaleneTriange) {
	EXPECT_EQ( get_triangle_type(10, 11, 12), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(12, 10, 11), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(11, 12, 10), TYPE_TRIANGLE_ISOSCELES );
}
