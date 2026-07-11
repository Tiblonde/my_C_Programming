#include <stdio.h>

float power(float base, int n);

int main(void) {
	float base;
	int n;

	printf("Enter the power (x^n): ");
	scanf("%f^%d", &base, &n);

	printf("The result is %.2f\n",power(base, n));

	return 0;
}

float power(float base, int n) {
	float temp;
	/* the iteration ends at n == 0 */
	if (n == 0)
		return 1.0f;
	/* make sure calculate power once */
	else if (n % 2 == 0) {
		temp = power(base, n/2);
		return temp*temp;
	}
	else {
		return base * power(base, n - 1);
	}
}
