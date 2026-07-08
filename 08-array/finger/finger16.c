#include <stdio.h>

int main(void) {
	char word[100];
	char ch;
	int i = 0;
	int alpha[26] = {0};

	printf("Enter first word: ");
	while((ch = getchar()) != '\n') {
		alpha[ch - 'a']++;
	}

	printf("Enter second word: ");
	while((ch = getchar()) != '\n')
		alpha[ch - 'a']--;

	for (i = 0; i < 26; i++)
		if (alpha[i] != 0) {
			printf("The words are not anagrams.\n");
			return 0;
		}
	
	printf("The words are anagrams.\n");
	return 0;
			
}
