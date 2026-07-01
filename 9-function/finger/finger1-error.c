/* selection and sort */
#include <stdio.h>

#define N 10

void selection_sort(int a[], int low, int high);
int find_max(int a[], int low, int high);

int main(void) {
	int a[N], i;

	printf("Enter %d number for sorting: ", N);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	selection_sort(a, 0, N-1);

	printf("The sorted array is: ");
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);

	return 0;
}

void selection_sort(int a[], int low, int high) {
	int max;
	max = find_max(a, low, high);
	if (low < max)	
	selection_sort(a, low, max);
}

int find_max(int a[], int low, int high){
	int i, j, tmp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (a[i] < a[j])
				break;
		}
		if (j == N-1 && a[i]>=a[j])
			break;
	}
	tmp = a[i];
	a[i] = a[high];
	a[high] = tmp;

	return high-1;
}
