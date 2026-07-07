// section 13.4
#include <stdio.h>
#include <ctype.h>

void capitalize(char *s);

int main(void) {
	char s[] = "Hello!";

 	capitalize(s);

	puts(s);
	return 0;
}

/* version 1 */
void capitalize(char *s) {
	int i = 0;
	while (s[i] != '\0')
		s[i] = toupper(s[i++]);
}