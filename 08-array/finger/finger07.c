#include <stdio.h>

int main(void) {
	int array[5][5] = {0};
	int i, j, value, sum = 0;

	for (i=0;i<5;i++){
		printf("Enter row %d:", i+1);
		for (j=0; j<5 ; j++) 
			scanf("%d", &array[i][j]);
	}
	
	printf("Row totals: ");
	for (i=0; i<5; i++) {
		for (j=0; j<5 ; j++)
			sum += array[i][j];
		printf("%d ", sum);
		sum = 0;
	} 
	putchar('\n');
	printf("Column totals: ");
	for (j=0; j<5; j++) {
		for (i=0; i<5 ; i++)
			sum += array[i][j];
		printf("%d ", sum);
		sum = 0;
	}
	putchar('\n');

	return 0;
}
