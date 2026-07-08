#include <stdio.h>
#include <ctype.h>

int main(void) {
	int sum = 0;
	char ch;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n')
		switch (tolower(ch)) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			sum += 1; break;
		}

	printf("Your sentence contains %d vowels.\n", sum);
	return 0;
}
