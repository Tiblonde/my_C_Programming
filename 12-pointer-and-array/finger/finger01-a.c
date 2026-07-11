#include <stdio.h>

int main(void) {
	char ch;
	char msg[99];
	int i = 0;

	printf("Enter a message: ");
	while((ch = getchar()) != '\n' || i == 99 + 1) 
		msg[i++] = ch;
	
	printf("Reversal is: ");
	for (i = i - 1;i >= 0;i--)
		putchar(msg[i]);

	putchar('\n');
	return 0;
}
