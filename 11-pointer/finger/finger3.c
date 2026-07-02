#include <stdio.h>


void reduce(int numerator, int denominator,
			int *reduced_numerator,
			int *reduced_denominator);

int main() {
	int numerator, denominator;
	int reduced_numerator, reduced_denominator;
	
	printf("Enter a fraction: ");
	scanf("%d/%d", &numerator, &denominator);

	reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
	printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

	return 0;
}

void reduce(int numerator, int denominator,
			int *reduced_numerator,
			int *reduced_denominator) {
	int i, min, reduce = 1;
	min = (numerator < denominator) ? numerator : denominator;
	for (i = 1; i <= min; i++)
		if ((numerator%i==0) && (denominator%i==0))
			reduce = i;

	*reduced_numerator = numerator/reduce;
	*reduced_denominator = denominator/reduce;
}
