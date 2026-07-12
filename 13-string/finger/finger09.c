#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);

int main(void) {
	int sum = 0;
	char msg[99];

	printf("Enter a sentence: ");
	scanf("%s", msg);
	sum = compute_vowel_count(msg);

	printf("Your sentence contains %d vowels.\n", sum);
	return 0;
}

int compute_vowel_count(const char *sentence) {
	int sum = 0;
	while (*sentence != '\0') {
		switch (tolower(*sentence)) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			sum += 1; break;
		}
		sentence++;
	}
	return sum;
}