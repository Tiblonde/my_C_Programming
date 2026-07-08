#include <stdio.h>

int main(void) {
	int length = 0, num = 0, flag = 0;
	char ch;

	printf("Enter a sentence: ");

	while ((ch = getchar()) != '\n') {
		if (ch != ' ' && flag == 0) {	/* represents that from this character, */
			flag = 1;					/* it has entered one word */
			num++;
		}

		if (ch == ' ' && flag == 1)
			flag = 0; /* represents that it out of word */

		if (flag == 1) 	/* counts the length of word */
			length++; 	
	}

	printf("Average word length: %.1f\n", length / (num * 1.0f));

	return 0;
}