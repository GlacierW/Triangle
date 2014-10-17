#include "triangle.h"
#include <gtest/gtest.h>

TEST( TriangleTest, NegativeEdge ) {
	// one negative edge
	EXPECT_EQ( get_triangle_type(-1, 1, 1), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(1, -1, 1), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(1, 1, -1), TYPE_TRIANGLE_INVALID_INPUT );
	
	// two negative edges 
	EXPECT_EQ( get_triangle_type(-1, -1, 1), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(1, -1, -1), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(-1, 1, -1), TYPE_TRIANGLE_INVALID_INPUT );
	
	// all negative edges 
	EXPECT_EQ( get_triangle_type(-1, -1, -1), TYPE_TRIANGLE_INVALID_INPUT );
}

TEST( TriangleTest, NormalBoundaryEdgeValue ) {
	// one at min bound
	EXPECT_EQ( get_triangle_type(1, 10, 10), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(10, 1, 10), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(10, 10, 1), TYPE_TRIANGLE_ISOSCELES );
	
	// two at min bound
	EXPECT_EQ( get_triangle_type(1, 1, 10), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(1, 10, 1), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(10, 1, 1), TYPE_TRIANGLE_NOTATRIANGLE );
	
	// all at min bound
	EXPECT_EQ( get_triangle_type(1, 1, 1), TYPE_TRIANGLE_EQUILATERAL );
	
	/* ----------------------------------- */
	
	// one at min + 1 bound
	EXPECT_EQ( get_triangle_type(2, 10, 10), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(10, 2, 10), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(10, 10, 2), TYPE_TRIANGLE_ISOSCELES );
	
	// two at min + 1 bound
	EXPECT_EQ( get_triangle_type(2, 2, 10), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(2, 10, 2), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(10, 2, 2), TYPE_TRIANGLE_NOTATRIANGLE );
	
	// all at min + 1 bound
	EXPECT_EQ( get_triangle_type(2, 2, 2), TYPE_TRIANGLE_EQUILATERAL );
	
	/* ----------------------------------- */
	
	// one at max bound
	EXPECT_EQ( get_triangle_type(200, 150, 150), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(150, 200, 150), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(150, 150, 200), TYPE_TRIANGLE_ISOSCELES );
	
	// two at max bound
	EXPECT_EQ( get_triangle_type(200, 200, 150), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(200, 150, 200), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(150, 200, 200), TYPE_TRIANGLE_ISOSCELES );
	
	// all at max bound
	EXPECT_EQ( get_triangle_type(200, 200, 200), TYPE_TRIANGLE_EQUILATERAL );
	
	/* ----------------------------------- */
	
	// one at max - 1 bound
	EXPECT_EQ( get_triangle_type(199, 150, 150), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(150, 199, 150), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(150, 150, 199), TYPE_TRIANGLE_ISOSCELES );
	
	// two at max - 1 bound
	EXPECT_EQ( get_triangle_type(199, 199, 150), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(199, 150, 199), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(150, 199, 199), TYPE_TRIANGLE_ISOSCELES );
	
	// all at max - 1 bound
	EXPECT_EQ( get_triangle_type(199, 199, 199), TYPE_TRIANGLE_EQUILATERAL );
	
	/* ----------------------------------- */
		
	// combination of min & max bound ( 1 min, 2 max )
	EXPECT_EQ( get_triangle_type(1, 200, 200), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(200, 1, 200), TYPE_TRIANGLE_ISOSCELES );
	EXPECT_EQ( get_triangle_type(200, 200, 1), TYPE_TRIANGLE_ISOSCELES );
	
	// combination of min & max bound ( 2 min, 1 max )
	EXPECT_EQ( get_triangle_type(200, 1, 1), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(1, 200, 1), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(1, 1, 200), TYPE_TRIANGLE_NOTATRIANGLE );
}

TEST( TriangleTest, RobustBoundaryEdgeValue ) {
	// one at min - 1 bound
	EXPECT_EQ( get_triangle_type(0, 10, 10), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(10, 0, 10), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(10, 10, 0), TYPE_TRIANGLE_INVALID_INPUT );
	
	// two at min - 1 bound
	EXPECT_EQ( get_triangle_type(0, 0, 10), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(0, 10, 0), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(10, 0, 0), TYPE_TRIANGLE_INVALID_INPUT );
	
	// all at min - 1 bound
	EXPECT_EQ( get_triangle_type(0, 0, 0), TYPE_TRIANGLE_INVALID_INPUT );
	
	/* ----------------------------------- */
	
	// one at max + 1 bound
	EXPECT_EQ( get_triangle_type(201, 150, 150), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(150, 201, 150), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(150, 150, 201), TYPE_TRIANGLE_INVALID_INPUT );
	
	// two at max + 1 bound
	EXPECT_EQ( get_triangle_type(201, 201, 150), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(201, 150, 201), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(150, 201, 201), TYPE_TRIANGLE_INVALID_INPUT );
	
	// all at max + 1 bound
	EXPECT_EQ( get_triangle_type(201, 201, 201), TYPE_TRIANGLE_INVALID_INPUT );
	
	/* ----------------------------------- */
	
	// combination of min - 1 & max + 1 ( 1 min-1, 2 max+1 )
	EXPECT_EQ( get_triangle_type(0, 201, 201), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(201, 0, 201), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(201, 201, 0), TYPE_TRIANGLE_INVALID_INPUT );
	
	// combination of min - 1 & max + 1 ( 2 min-1, 1 max+1 )
	EXPECT_EQ( get_triangle_type(201, 0, 0), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(0, 201, 0), TYPE_TRIANGLE_INVALID_INPUT );
	EXPECT_EQ( get_triangle_type(0, 0, 201), TYPE_TRIANGLE_INVALID_INPUT );
}

TEST( TriangleTest, NotTriangle ) {
	EXPECT_EQ( get_triangle_type(1, 2, 3), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(1, 3, 2), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(2, 1, 3), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(3, 1, 2), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(3, 2, 1), TYPE_TRIANGLE_NOTATRIANGLE );
	EXPECT_EQ( get_triangle_type(2, 3, 1), TYPE_TRIANGLE_NOTATRIANGLE );
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
	EXPECT_EQ( get_triangle_type(10, 11, 12), TYPE_TRIANGLE_SCALENE );
	EXPECT_EQ( get_triangle_type(12, 10, 11), TYPE_TRIANGLE_SCALENE );
	EXPECT_EQ( get_triangle_type(11, 12, 10), TYPE_TRIANGLE_SCALENE );
}
