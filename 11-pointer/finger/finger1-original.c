#include <stdio.h>

//void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
	int dollars, i;
	int bills[4] = {0};
	int num[4] = {20, 10, 5, 1};

	printf("Enter a dollar amount: ");
	scanf("%d", &dollars);

	bills[0] = dollars / 20;
	bills[1] = (dollars - bills[0]*20 ) / 10;
	bills[2] = (dollars - bills[0]*20 - bills[1]*10) / 5;
	bills[3] = (dollars - bills[0]*20 - bills[1]*10 - bills[2]*5);

	for (i=0; i<4; i++)
		printf("$%d bills: %d\n",num[i] ,bills[i]);

	return 0;
}
