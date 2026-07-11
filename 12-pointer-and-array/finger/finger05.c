#include <stdio.h>

int main(void) {
	char sentence[100];
	char ch;
	char *p = sentence, *end, *start;

	printf("Enter a sentence: ");
	while(ch = getchar()) {
		if (ch == '.' || ch == '?' || ch == '!') {
			*p = ch;
			break;
		}
		*(p++) = ch;
	}

	printf("Reversal of sentence: ");

	end = p;

	int flag = 0;
	for (--p; p >= sentence ; p--) {
		if (*p == ' '){
			start = p + 1;
			flag = 1;
		}
		else if (p == sentence) {
			start = p;
			flag = 2;
		}

		if (flag){
			for (; start < end  ;start++)
				putchar(*start);
			flag == 1 ? putchar(' ') : putchar(ch);
			end = p;
			flag = 0;
		}
	}
	putchar('\n');

	return 0;

}
