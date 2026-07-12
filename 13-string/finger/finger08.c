#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *word);

int main(void) {
	int sum = 0;
	char msg[99];

	printf("Enter a word: ");
	scanf("%s", msg);
	sum = compute_scrabble_value(msg);
	printf("Srabble value: %d\n", sum);
	return 0;
}

int compute_scrabble_value(const char *word) {
	int sum = 0;
	while (*word != '\0') {
		switch(toupper(*word)) {
			case 'A': case 'E': case 'I': case 'L':
			case 'N': case 'O': case 'R': case 'S':
			case 'T': case 'U': sum += 1; break;
			case 'D': case 'G': sum += 2; break;
			case 'B': case 'C': case 'M': case 'P':
			sum += 3; break;
			case 'F': case 'H': case 'V': case 'W':
			case 'Y': sum += 4; break;
			case 'K': sum += 5; break;
			case 'J': case 'X': sum += 8; break;
			case 'Q': case 'Z': sum += 10; break;
			default: break;
		}
		word++;
	}
	return sum;
}