#include <stdio.h>
#include <ctype.h>

int main(void) {
	int flag = 0;
	char ch, fn;

	printf("Enter a first and last name: ");
	
	while ((ch = getchar()) == ' ' && !isalpha(ch)) ; /* skip space to the first letter of first name */
	fn = ch;
	while (isalpha(ch = getchar())); /* skip remaining first name to space*/
	
	printf("Already handle with first name!\n");
	
	while (ch == ' ' && !isalpha(ch)) /* skip space to letter */
		ch = getchar();
	while (isalpha(ch)) {
		putchar(ch);
		ch = getchar();
	}
	
	printf(", %c\n", fn);
	
	return 0;
}
