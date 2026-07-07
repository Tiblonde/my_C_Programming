#include <stdio.h>
#include <string.h>

#define MAX_WORD 20

int main(void) {
	char smallest_word[MAX_WORD + 1], largest_word[MAX_WORD + 1];
	char word[MAX_WORD + 1];
	int read = 1;

	printf("Enter word: ");
	scanf("%s", word);
	strcpy(smallest_word, word);
	strcpy(largest_word,word);

	while (read) {
		printf("Enter word: ");
		scanf("%s", word);
		if (strlen(word) == 4)
			read = 0;
		if (strcmp(word, smallest_word) < 0)
			strcpy(smallest_word, word);
		if (strcmp(word, largest_word) > 0)
			strcpy(largest_word, word);
	}

	printf("Smallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
