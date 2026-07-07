#include <stdio.h>

typedef int Bool;

int main() {
	long nu;
	int i, digit, flag = 0;
	int digits_map[10]={0};

	printf("Enter a long integer: ");
	scanf("%ld", &nu);

	while (nu){
		digit = nu%10;
		if(digits_map[digit])
			flag = 1;
		digits_map[digit] += 1;
		nu = nu/10;
	}

	if (flag){
		printf("Digit: \t\t");
		for (i = 0; i < 10; i++)
			printf("%d ", i);
		printf("\nOccurrences: \t");
		for (i = 0; i < 10; i++)
			printf("%d ", digits_map[i]);
		printf("\n");
	}
	else
		printf("No repeated digit.\n");

	return 0;
}
