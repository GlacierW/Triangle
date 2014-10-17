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
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(1, 10, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 1, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 10, 1) );
	
	// two at min bound
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 1, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 10, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(10, 1, 1) );
	
	// all at min bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(1, 1, 1) );
	
	/* ----------------------------------- */
	
	// one at min + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(2, 10, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 2, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 10, 2) );
	
	// two at min + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 2, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 10, 2) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(10, 2, 2) );
	
	// all at min + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(2, 2, 2) );
	
	/* ----------------------------------- */
	
	// one at max bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(200, 150, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 200, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 150, 200) );
	
	// two at max bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(200, 200, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(200, 150, 200) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 200, 200) );
	
	// all at max bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(200, 200, 200) );
	
	/* ----------------------------------- */
	
	// one at max - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(199, 150, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 199, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 150, 199) );
	
	// two at max - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(199, 199, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(199, 150, 199) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(150, 199, 199) );
	
	// all at max - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(199, 199, 199) );
	
	/* ----------------------------------- */
		
	// combination of min & max bound ( 1 min, 2 max )
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(1, 200, 200) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(200, 1, 200) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(200, 200, 1) );
	
	// combination of min & max bound ( 2 min, 1 max )
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(200, 1, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 200, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 1, 200) );
}

TEST( TriangleTest, RobustBoundaryEdgeValue ) {
	// one at min - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 10, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(10, 0, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(10, 10, 0) );
	
	// two at min - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 0, 10) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 10, 0) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(10, 0, 0) );
	
	// all at min - 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 0, 0) );
	
	/* ----------------------------------- */
	
	// one at max + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 150, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(150, 201, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(150, 150, 201) );
	
	// two at max + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 201, 150) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 150, 201) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(150, 201, 201) );
	
	// all at max + 1 bound
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 201, 201) );
	
	/* ----------------------------------- */
	
	// combination of min - 1 & max + 1 ( 1 min-1, 2 max+1 )
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 201, 201) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 0, 201) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 201, 0) );
	
	// combination of min - 1 & max + 1 ( 2 min-1, 1 max+1 )
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 0, 0) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 201, 0) );
	EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 0, 201) );
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
