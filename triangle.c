#include <stdio.h>
#include "triangle.h"

int get_triangle_type( int edge_a, int edge_b, int edge_c ) {
	
	// check invalid input
	if( 
		edge_a > TRIANGLE_EDGE_MAX || edge_a < TRIANGLE_EDGE_MIN
	||	edge_b > TRIANGLE_EDGE_MAX || edge_b < TRIANGLE_EDGE_MIN
	||	edge_c > TRIANGLE_EDGE_MAX || edge_c < TRIANGLE_EDGE_MIN 
	) {
		return TYPE_TRIANGLE_INVALID_INPUT;
	}
		
	// check if the edges can form a triangle
	if(
		edge_a + edge_b <= edge_c
	||	edge_a + edge_c <= edge_b
	||	edge_b + edge_c <= edge_a
	) {
		return TYPE_TRIANGLE_NOTATRIANGLE;
	}
	
	return 0xdeadbeef;
}
