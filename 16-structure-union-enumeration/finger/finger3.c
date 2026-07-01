#include <stdio.h>

struct complex {
	double re, im;
};

struct complex make_complex(struct complex c, double re, double im);
struct complex add_complex(struct complex c1, struct complex c2);


int main() {
	struct complex c1, c2, c3;
	double re=1.0, im=0.0;	

	c1 = make_complex(c1, re, im);
	c2 = make_complex(c2, re, im);
	printf("c1: %f, %f\n", c1.re, c1.im);	
	printf("c2: %f, %f\n", c2.re, c2.im);	

	c3 = add_complex(c1, c2);
	printf("c3: %f, %f\n", c3.re, c3.im);	
	
	return 0;
}

struct complex make_complex(struct complex c, double re, double im) {
	c.re = re;
	c.im = im;
	return c;
}

struct complex add_complex(struct complex c1, struct complex c2) {
	struct complex ct;
	ct.re = c1.re + c2.re;
	ct.im = c1.im + c2.im;
	return ct;
}
