#include "triangle.h"
#include <gtest/gtest.h>

/*****
 * Specification-based Testing
 *****/
TEST( TriangleSpecTest, NegativeEdge ) {
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

TEST( TriangleSpecTest, NormalBoundaryEdgeValue ) {
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

TEST( TriangleSpecTest, RobustBoundaryEdgeValue ) {
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

TEST( TriangleSpecTest, NotTriangle ) {
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 2, 3) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 3, 2) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 1, 3) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(3, 1, 2) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(3, 2, 1) );
	EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 3, 1) );
}

TEST( TriangleSpecTest, EquilateralTriange ) {
	EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(10, 10, 10) );
}

TEST( TriangleSpecTest, IsoscelesTriange ) {
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 100, 100) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(100, 10, 100) );
	EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(100, 100, 10) );
}

TEST( TriangleSpecTest, ScaleneTriange) {
	EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(10, 11, 12) );
	EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(12, 10, 11) );
	EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(11, 12, 10) );
}


/*****
 * Code-based Testing
 *****/
// Statement coverage
TEST( TriangleCodeTest, CodeCoverageC0 ) {
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, 1, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 2, 3) );
    EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(10, 10, 10) );
    EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(10, 10, 15) );
    EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(3, 4, 5) );
}

// DD-path coverage
TEST( TriangleCodeTest, CodeCoverageC1 ) {

    // for the first branch
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, 1, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(1, 1, 1) ); 

    // for the second branch
    EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 2, 3) );
    EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(2, 3, 4) );

    // for the third branch, the false condition is included in the 4th case
    EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(2, 2, 3) );
    
    // for the fourth branch, all included in the 2nd, and the 5th cases
}

// DD-path coverage + Simple loop coverage
TEST( TriangleCodeTest, CodeCoverageC2 ) {
    
    // same as CodeCoverageC1 since no loop in code

    // for the first branch
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(-1, 1, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(1, 1, 1) ); 

    // for the second branch
    EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 2, 3) );
    EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(2, 3, 4) );

    // for the third branch, the false condition is included in the 4th case
    EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(2, 2, 3) );
    
    // for the fourth branch, all included in the 2nd, and the 5th cases
}

// Multiple-Condition coverage
TEST( TriangleCodeTest, CodeCoverageMCDC ) {

    // for the first branch
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(201, 1, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, 201, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, 1, 201) );
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(0, 1, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, 0, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_INVALID_INPUT, get_triangle_type(1, 1, 0) );
    EXPECT_EQ( TYPE_TRIANGLE_EQUILATERAL, get_triangle_type(1, 1, 1) );

    // for the second branch
    EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(1, 2, 3) );
    EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(2, 3, 1) );
    EXPECT_EQ( TYPE_TRIANGLE_NOTATRIANGLE, get_triangle_type(3, 2, 1) );

    // for the third branch
    EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(2, 2, 3) );
    EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(2, 3, 2) );
    EXPECT_EQ( TYPE_TRIANGLE_ISOSCELES, get_triangle_type(3, 2, 2) );
    EXPECT_EQ( TYPE_TRIANGLE_SCALENE, get_triangle_type(2, 3, 4) );
}
