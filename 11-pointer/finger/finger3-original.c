#include <stdio.h>


/*
void reduce(int numerator, int denominator,
			int *reduced_numerator,
			int *reduced_denominator);
*/

int main() {
	int numerator, denominator, reduce = 1;
	int i, min;
	
	printf("Enter a fraction: ");
	scanf("%d/%d", &numerator, &denominator);

	min = (numerator < denominator) ? numerator : denominator;
	for (i = 1; i <= min; i++)
		if ((numerator % i == 0) && (denominator % i == 0))
			reduce = i;

	printf("In lowest terms: %d/%d\n", numerator / reduce, denominator / reduce);

	return 0;
}
