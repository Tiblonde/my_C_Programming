#include <stdio.h>

int main(void) {
	char words[30][20];
	char ch;
	int i = 0, j = 0, k, start, end;

	/* store input into sentence; end with ./?/! */
	printf("Enter a sentence: ");
	while(ch = getchar()) {
		if (ch == '.' || ch == '?' || ch == '!') {
			words[i][j++] = '\0';
			end = ch;
			break;
		}
		ch == ' ' ? (words[i][j++] = '\0', i++, j=0 ): (words[i][j++] = ch);
	}

	printf("Reversal of sentence: ");
	for (;i>=0; i--)
		printf("%s ", words[i]);
	putchar(end);
	
	putchar('\n');

	return 0;

}
