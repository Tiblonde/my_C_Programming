#include <stdio.h>

void reverse(char *message);

int main(void) {
	char msg[99];

	printf("Enter a message: ");
	scanf("%s", msg);

	reverse(msg);
	
	printf("Reversal is: ");
	printf("%s", msg);

	putchar('\n');
	return 0;
}

void reverse(char *message) {
	char *start = message, *end, tmp;
	while (*message != '\0') message++;
	end = message-1;

	for (;start < end; start++, end--) {
		tmp = *start;
		*start = *end;
		*end = tmp;
	}
}
