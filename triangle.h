#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#define TRIANGLE_EDGE_MIN		1
#define TRIANGLE_EDGE_MAX		200

#define TYPE_TRIANGLE_INVALID		0
#define TYPE_TRIANGLE_EQUILATERAL	1
#define TYPE_TRIANGLE_ISOSCELES		2
#define TYPE_TRIANGLE_SCALENE		3

int get_triangle_type( int edge_a, int edge_b, int edge_c );

#endif
