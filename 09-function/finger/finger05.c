/*
 * Orinial is Chapter8 finger17
 */

#include <stdio.h>

void create_magic_square(int n, int magic_square[99][99]);
void print_magic_square(int n, int magic_square[99][99]);

int main(void) {

	int num;
	printf("This program creates a magic square of a specified size.\n"
		   "The size must be an odd number between 1 and 99.\n"
		   "Enter size of magic square: ");
	scanf("%d", &num);

	int magic_square[99][99] = {0};

	create_magic_square(num, magic_square);
	print_magic_square(num, magic_square);

	return 0;
}

void create_magic_square(int n, int magic_square[99][99]) {
	int y = (n - 1) / 2, x = 0;
	int i, j;
	int number = 1;
	int xn, yn;

	magic_square[x][y] = number;

	while (number != 25) {
		xn = (x - 1 + n) % n;
		yn = (y + 1) % n;
		
		if (magic_square[xn][yn] == 0){
			x = xn;
			y = yn;
		}
		else
			x = (x + 1)%n;

		magic_square[x][y] = ++number;
	}
}

void print_magic_square(int n, int magic_square[99][99]) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3d", magic_square[i][j]);
		putchar('\n');
	}
}
