#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch;
	char msg[99];
	char *p = msg, *np = msg;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && p < (msg + 99)) 
		if (isalpha(ch))
			*(p++) = tolower(ch);

	for (--p;p >= msg;p--)
		if (*p != *(np++)) {
			printf("Not a palindrome\n");
			return 0;
		}

	printf("Palindrome\n");
	return 0;
}
