/* Prints a table of squares using an off method */

#include <stdio.h>

int main(void) {
	int i, n, odd, square;

	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	i = 1;
	odd = 3;
	for (square = 1; i <= n; odd +=2) {
		printf("%10d%10d\n", i, square); // 1 1, 2 4, 3 9
		++i;
		square += odd;
	}
	return 0;
}