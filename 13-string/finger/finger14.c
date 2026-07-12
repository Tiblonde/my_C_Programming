#include <stdio.h>
#include <stdbool.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
	char word1[100], word2[100];

	printf("Enter first word: ");
	scanf("%s", word1);

	printf("Enter second word: ");
	scanf("%s", word2);

	if (are_anagrams(word1, word2)) {
		printf("The words are anagrams.\n");
	} else
		printf("The words are not anagrams.\n");
	return 0;
			
}

bool are_anagrams(const char *word1, const char *word2) {
	int alpha[26] = {0}, i;

	/* asume same length */
	while (*word1 != '\0') {
		alpha[*(word1++) - 'a']++;
		alpha[*(word2++) - 'a']--;
	}

	for (i = 0; i < 26; i++)
		if (alpha[i] != 0)
			return false;
	return true;
}