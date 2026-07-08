#include <stdio.h>

int main(void) {
	int array[5][5] = {0};
	int i, j, value, sum = 0;

	for (i=0;i<5;i++){
		printf("Student %d, please enter grades:", i+1);
		for (j=0; j<5 ; j++) 
			scanf("%d", &array[i][j]);
	}
	
	printf("Every student's sum of grades: ");
	for (i=0; i<5; i++) {
		for (j=0; j<5 ; j++)
			sum += array[i][j];
		printf("%d ", sum);
		sum = 0;
	} 
	putchar('\n');

	printf("Every student's avg of grades: ");
	for (i=0; i<5; i++) {
		for (j=0; j<5 ; j++)
			sum += array[i][j];
		printf("%.1f ", sum/5.0);
		sum = 0;
	} 
	putchar('\n');
	
	printf("Every subject's avg: ");
	for (j=0; j<5; j++) {
		for (i=0; i<5 ; i++)
			sum += array[i][j];
		printf("%.1f ", sum/5.0);
		sum = 0;
	}
	putchar('\n');


	printf("Every subject's highest ");
	int high;
	for (j=0; j<5; j++) {
		high = array[0][j];
		for (i=0; i<5 ; i++)
			if (array[i][j] >= high)
				high = array[i][j];
		printf("%d ", high);
	}
	putchar('\n');

	printf("Every subject's lowest ");
	int low;
	for (j=0; j<5; j++) {
		low = array[0][j];
		for (i=0; i<5 ; i++)
			if (array[i][j] <= low)
				low = array[i][j];
		printf("%d ", low);
	}
	putchar('\n');

	return 0;
}
