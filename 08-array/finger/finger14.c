#include <stdio.h>

int main(void) {
	char sentence[100];
	char ch;
	int i = 0, j, k, start, end;

	printf("Enter a sentence: ");
	while(ch = getchar()) {
		if (ch == '.' || ch == '?' || ch == '!') {
			sentence[i] = ch;
			break;
		}
		sentence[i++] = ch;
	}

	printf("Reversal of sentence: ");

	end = i;

	int flag = 0;
	for (j = i-1; j>=0 ; j--) {
		if (sentence[j] == ' '){
			start = j+1;
			flag = 1;
		}
		else if (j == 0 ) {
			start = j;
			flag = 1;
		}

		if (flag){
			for (k=start; k<end  ;k++)
				putchar(sentence[k]);
			start != 0 ? putchar(' ') : putchar(sentence[i]);
			end = j;
			flag = 0;
		}
	}
	putchar('\n');

	return 0;

}
