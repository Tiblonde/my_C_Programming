#include <stdio.h>
#include <math.h>

int main(void) {
	double x; /* To */
	double y; /* Guessed number Y */

	printf("Enter a positive number: ");
	scanf("%lf", &x);

	y = 1;
	while (fabs(y * y - x) >= (0.000001 * y)) {
		y = (x / y + y) / 2.0;
	}

	printf("Square root: %lf\n", y);

	return 0;

}