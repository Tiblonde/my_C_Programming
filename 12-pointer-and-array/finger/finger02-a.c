#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch;
	char msg[99];
	int i = 0, n;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && i < 99) 
		if (isalpha(ch))
			msg[i++] = tolower(ch);

	int j;
	for (j = 0; j < i; j++)
		putchar(msg[j]);
	putchar('\n');

	for (n = --i;i >= 0;i--)
		if (msg[i] != msg[n-i]) {
			printf("Not a palindrome\n");
			return 0;
		}

	printf("Palindrome\n");
	return 0;
}
