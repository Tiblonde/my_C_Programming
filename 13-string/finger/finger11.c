#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main(void) {
	int length = 0, num = 0, flag = 0;
	char sentence[99];
	double avg;

	printf("Enter a sentence: ");
	gets(sentence);
	avg = compute_average_word_length(sentence);

	printf("Average word length: %.1f\n", avg);

	return 0;
}

double compute_average_word_length(const char *sentence) {
	int flag = 0, length = 0, num = 0;

	while (*sentence != '\0') {
		if (*sentence != ' ' && flag == 0) {
			flag = 1;
			num++;
		}
		if (*sentence == ' ' && flag == 1)
			flag = 0;

		if (flag)
			length++;
		sentence++;
	}

	return length / (num * 1.0f);
}
