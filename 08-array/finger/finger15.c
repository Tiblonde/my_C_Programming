#include <stdio.h>

int main(void) {
	char msg[80];
	char ch;
	int i = 0, j;
	int shift;

	printf("Enter message to be encrypted: ");
	while ((ch = getchar()) != '\n')
		msg[i++] = ch;
	msg[i] = '\0';

	printf("Enter shift amount(1-25): ");
	scanf("%d", &shift);

	for(j=0; (ch = msg[j])!='\0' ;j++) {
		if (ch >= 'A' && ch <= 'Z')
			ch = (ch - 'A' + shift) % 26 + 'A';
		else if (ch >= 'a' && ch <= 'z')
			ch = (ch - 'a' + shift) % 26 + 'a';

		putchar(ch);
	}
	putchar('\n');

	return 0;
}
