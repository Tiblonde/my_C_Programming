#include <stdio.h>

int main(void) {
	char ch;
	char number[15] = {0};
	int value = 0;
	int i = 0, j;

	printf("Enter phone number: ");
	while((ch = getchar()) != '\n') {
		switch(ch) {
		case 'A': case 'B': case 'C': number[i++]='2'; break;
		case 'D': case 'E': case 'F': number[i++]='3'; break;
		case 'G': case 'H': case 'I': number[i++]='4'; break;
		case 'J': case 'K': case 'L': number[i++]='5'; break;
		case 'M': case 'N': case 'O': number[i++]='6'; break;
		case 'P': case 'Q': case 'R': case 'S': number[i++]='7'; break;
		case 'T': case 'U': case 'V': number[i++]='8'; break;
		case 'W': case 'X': case 'Y': case 'Z': number[i++]='9'; break;
		default: number[i++]=ch; break;
		}
		
	}

	for (j=0;j<i;j++)
		putchar(number[j]);
	putchar('\n');
	
	return 0;
}
