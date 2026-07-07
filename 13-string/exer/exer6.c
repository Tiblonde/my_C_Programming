#include <stdio.h>

void censor(char *s);

int main(void) {
	char *s = "food fool";

	censor(s);

	puts(s);
	return 0;
}

void censor(char *s) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'o')
			s[i] = s[i+1] = s[i+2] = 'x';
		i++;
	}
}