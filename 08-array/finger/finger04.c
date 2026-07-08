#include <stdio.h>

#define N 10

#define LENGTH(x) (int)(sizeof(x) / sizeof(x[0]))

int main(void) {
	int a[N], i;

	printf("Enter %d numbers: ", N);
	for (i = 0; i < LENGTH(a); i++)
		scanf("%d", &a[i]);

	printf("Inverse order:");
	for (i = LENGTH(a) - 1; i >= 0; i--)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
