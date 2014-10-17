#include "triangle.h"
#include <gtest/gtest.h>

TEST( TriangleTest, NegativeEdge ) {
	// one negative edge
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, 1, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, -1, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, 1, -1) );
	
	// two negative edges 
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, -1, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, -1, -1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, 1, -1) );
	
	// all negative edges 
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, -1, -1) );
}

TEST( TriangleTest, NormalBoundaryEdgeValue ) {
	// one at min bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MIN, 10, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, TRIANGLE_EDGE_MIN, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 10, TRIANGLE_EDGE_MIN) );
	
	// two at min bound
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MIN, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MIN, 10, TRIANGLE_EDGE_MIN) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(10, TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MIN) );
	
	// all at min bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MIN) );
	
	/* ----------------------------------- */
	
	// one at min + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MIN + 1, 10, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, TRIANGLE_EDGE_MIN + 1, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 10, TRIANGLE_EDGE_MIN + 1) );
	
	// two at min + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MIN + 1, TRIANGLE_EDGE_MIN + 1, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MIN + 1, 10, TRIANGLE_EDGE_MIN + 1) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(10, TRIANGLE_EDGE_MIN + 1, TRIANGLE_EDGE_MIN + 1) );
	
	// all at min + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(TRIANGLE_EDGE_MIN + 1, TRIANGLE_EDGE_MIN + 1, TRIANGLE_EDGE_MIN + 1) );
	
	/* ----------------------------------- */
	
	// one at max bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX, 150, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, TRIANGLE_EDGE_MAX, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 150, TRIANGLE_EDGE_MAX) );
	
	// two at max bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX, TRIANGLE_EDGE_MAX, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX, 150, TRIANGLE_EDGE_MAX) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, TRIANGLE_EDGE_MAX, TRIANGLE_EDGE_MAX) );
	
	// all at max bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(TRIANGLE_EDGE_MAX, TRIANGLE_EDGE_MAX, TRIANGLE_EDGE_MAX) );
	
	/* ----------------------------------- */
	
	// one at max - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX - 1, 150, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, TRIANGLE_EDGE_MAX - 1, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 150, TRIANGLE_EDGE_MAX - 1) );
	
	// two at max - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX - 1, TRIANGLE_EDGE_MAX - 1, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX - 1, 150, TRIANGLE_EDGE_MAX - 1) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, TRIANGLE_EDGE_MAX - 1, TRIANGLE_EDGE_MAX - 1) );
	
	// all at max - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(TRIANGLE_EDGE_MAX - 1, TRIANGLE_EDGE_MAX - 1, TRIANGLE_EDGE_MAX - 1) );
	
	/* ----------------------------------- */
		
	// combination of min & max bound ( 1 min, 2 max )
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(1, TRIANGLE_EDGE_MAX - 1, TRIANGLE_EDGE_MAX - 1) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX - 1, 1, TRIANGLE_EDGE_MAX - 1) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(TRIANGLE_EDGE_MAX - 1, TRIANGLE_EDGE_MAX - 1, 1) );
	
	// combination of min & max bound ( 2 min, 1 max )
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MAX, TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MIN) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MAX, TRIANGLE_EDGE_MIN) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MIN, TRIANGLE_EDGE_MAX) );
}

TEST( TriangleTest, RobustBoundaryEdgeValue ) {
	// one at min - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, 10, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(10, TRIANGLE_EDGE_MIN - 1, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(10, 10, TRIANGLE_EDGE_MIN - 1) );
	
	// two at min - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MIN - 1, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, 10, TRIANGLE_EDGE_MIN - 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(10, TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MIN - 1) );
	
	// all at min - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MIN - 1) );
	
	/* ----------------------------------- */
	
	// one at max + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, 150, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(150, TRIANGLE_EDGE_MAX + 1, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(150, 150, TRIANGLE_EDGE_MAX + 1) );
	
	// two at max + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MAX + 1, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, 150, TRIANGLE_EDGE_MAX + 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(150, TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MAX + 1) );
	
	// all at max + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MAX + 1) );
	
	/* ----------------------------------- */
	
	// combination of min - 1 & max + 1 ( 1 min-1, 2 max+1 )
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MAX + 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MAX + 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MIN - 1) );
	
	// combination of min - 1 & max + 1 ( 2 min-1, 1 max+1 )
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MIN - 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MAX + 1, TRIANGLE_EDGE_MIN - 1) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MIN - 1, TRIANGLE_EDGE_MAX + 1) );
}

TEST( TriangleTest, NotTriangle ) {
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 2, 3) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 3, 2) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 1, 3) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(3, 1, 2) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(3, 2, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 3, 1) );
}

TEST( TriangleTest, EquilateralTriange ) {
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(10, 10, 10) );
}

TEST( TriangleTest, IsoscelesTriange ) {
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 100, 100) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(100, 10, 100) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(100, 100, 10) );
}

TEST( TriangleTest, ScaleneTriange) {
	EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(10, 11, 12) );
	EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(12, 10, 11) );
	EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(11, 12, 10) );
}
