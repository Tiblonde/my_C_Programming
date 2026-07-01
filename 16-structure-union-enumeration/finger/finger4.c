#include <stdio.h>

typedef struct{
	double re, im;
} Complex;

Complex make_complex(Complex c, double re, double im);
Complex add_complex(Complex c1, Complex c2);


int main() {
	Complex c1, c2, c3;
	double re=1.0, im=0.0;	

	c1 = make_complex(c1, re, im);
	c2 = make_complex(c2, re, im);
	printf("c1: %f, %f\n", c1.re, c1.im);	
	printf("c2: %f, %f\n", c2.re, c2.im);	

	c3 = add_complex(c1, c2);
	printf("c3: %f, %f\n", c3.re, c3.im);	
	
	return 0;
}

Complex make_complex(Complex c, double re, double im) {
	c.re = re;
	c.im = im;
	return c;
}

Complex add_complex(Complex c1, Complex c2) {
	Complex ct;
	ct.re = c1.re + c2.re;
	ct.im = c1.im + c2.im;
	return ct;
}
