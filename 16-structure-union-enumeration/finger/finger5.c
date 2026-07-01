#include <stdio.h>

struct point {float x, y;};
struct rectangle { struct point upper_left, lower_right;};
typedef int Bool;

struct point 		make_point			(float x, float y);
struct rectangle 	make_rect			(struct point, struct point);
/* Compute the area based on structure rectangle*/
float 				compute_area		(struct rectangle rt);
/* Determine the center of the rectangle */
struct point		determine_center	(struct rectangle rt);
/* Move the rectangle */
struct rectangle	move_rectangle		(struct rectangle, float, float);
/* Determine whether a point is in the r */
Bool 				determine_inside	(struct rectangle, struct point);

int main() {	
	struct point p1, p2, p3, p4;
	struct rectangle rt;
	float area;

	p1 = make_point(0.0, 0.0);
	p2 = make_point(12.2, 42.5);
	rt = make_rect(p1, p2);
	printf("p1: %f, %f\n", p1.x, p1.y);	
	printf("p2: %f, %f\n", p2.x, p2.y);	

	area = compute_area(rt);
	printf("Area of rectangel is: %f\n", area);

	p3 = determine_center(rt);
	printf("p3: %f, %f\n", p3.x, p3.y);	
	
	rt = move_rectangle(rt, 2.5, 7.9);
	printf("rt: (%f, %f), (%f, %f)\n", 
			rt.upper_left.x, rt.upper_left.y,
			rt.lower_right.x, rt.lower_right.y);	
	
	printf("Enter the point location (x,y): ");
	scanf("(%f,%f)", &p4.x, &p4.y);

	if (determine_inside(rt, p4))
		printf("The point is inside.\n");
	else
		printf("The point is outside.\n");
		

	return 0;
}

struct point make_point (float x, float y) {
	struct point pt;
	pt.x = x;
	pt.y = y;

	return pt;
}

struct rectangle make_rect( struct point p1, struct point p2) {
	struct rectangle rect;
	rect.upper_left = p1;
	rect.lower_right = p2;

	return rect;
}

float compute_area(struct rectangle rect) {
	float length, width;

	length = rect.lower_right.x - rect.upper_left.x;
	width  = rect.lower_right.y - rect.upper_left.y;

	return length * width;
}

struct point determine_center (struct rectangle rect) {
	struct point p;
	
	p.x = (rect.lower_right.x + rect.upper_left.x) / 2;
	p.y = (rect.lower_right.y + rect.upper_left.y) / 2;
	
	return p;
}

struct rectangle move_rectangle (struct rectangle rect, float x, float y) {
	rect.lower_right.x += x;
	rect.lower_right.y += y;
	rect.upper_left.x += x;
	rect.upper_left.y += y;
	return rect;
}

Bool determine_inside (struct rectangle r, struct point p) {
	Bool det = p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
			   p.y >= r.upper_left.y && p.y <= r.lower_right.y;

	return det;
}
