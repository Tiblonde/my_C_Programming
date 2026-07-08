#include <stdio.h>

int main(void) {

	int num;
	int square[99][99] = {0};

	printf("This program creates a magic square of a specified size.\n"
		   "The size must be an odd number between 1 and 99.\n"
		   "Enter size of magic square: ");
	scanf("%d", &num);

	int y = (num - 1) / 2, x = 0, xn, yn;
	int value = 1;
	square[x][y] = value;
	while (value != num*num) {
		xn = (x + num - 1)%num;
		yn = (y + 1)%num;

		if (square[xn][yn] == 0) {
			x = xn;
			y = yn;
		}
		else {
			x = (x + 1)%num;
			y = y;
		}
		square[x][y] = ++value;
	}

	int i, j;
	for (i=0;i<num;i++){
		for (j=0;j<num;j++)
			printf("%2d ", square[i][j]);
		printf("\n");
	}

	return 0;
}
