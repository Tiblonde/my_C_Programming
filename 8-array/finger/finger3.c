#include <stdio.h>

#define TRUE 	1
#define FALSE 	0

typedef int Bool;

int main() {
	long nu;
	int digit;
	Bool digits_map[10]={FALSE};

	do {
		printf("Enter a long integer: ");
		scanf("%ld", &nu);
		
		if (nu < 0)
			break;
		
		while (nu){
			digit = nu%10;
			if(digits_map[digit])
				break;
			digits_map[digit] = TRUE;
			nu = nu/10;
		}

		if (nu)
			printf("Repeated digit.\n");
		else
			printf("No repeated digit.\n");
	} while (1);

	return 0;
}
