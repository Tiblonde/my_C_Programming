#include <stdio.h>

void encrypt(char *message, int shift);

int main(void) {
	char msg[80];
	char ch;
	int i = 0, j;
	int shift;

	printf("Enter message to be encrypted: ");
	while ((ch = getchar()) != '\n')
		msg[i++] = ch;
	msg[i] = '\0';

	printf("Enter shift amount(1-25): ");
	scanf("%d", &shift);

	encrypt(msg, shift);

	puts(msg);

	return 0;
}

void encrypt(char *message, int shift) {
	for (;*message != '\0'; message++) {
		if (*message >= 'A' && *message <= 'Z')
			*message = (*message - 'A' + shift) % 26 + 'A';
		if (*message >= 'a' && *message <= 'z')
			*message = (*message - 'a' + shift) % 26 + 'a';
	}
}