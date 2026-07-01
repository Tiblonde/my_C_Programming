#include <stdio.h>

int main() {
	struct {
		double re, im;
	} c1 = {0.0, 1.0}
	, c2 = {1.0, 0.0}
	, c3;

	// Copy c2 to c1 (Version.1)
	//c1.re = c2.re;
	//c1.im = c2.im;
	// Copy c2 to c1 (Version.2)
	c1 = c2;

	printf("c1: %f, %f\n", c1.re, c1.im);
	
	return 0;
}
