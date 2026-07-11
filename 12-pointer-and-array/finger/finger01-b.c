#include <stdio.h>

int main(void) {
	char ch;
	char msg[99];
	char *p = msg;

	printf("Enter a message: ");
	while((*p = getchar()) != '\n' && p < (msg + 99)) 
		p++;
	
	printf("Reversal is: ");
	for (p--;p >= msg;p--)
		putchar(*p);

	putchar('\n');
	return 0;
}
