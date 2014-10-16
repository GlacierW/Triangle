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


