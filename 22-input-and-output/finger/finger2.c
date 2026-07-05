#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int ch;
	
	if (argc != 2) {
		printf("Usage: filename\n");
		exit(EXIT_FAILURE);
	}
	
	if ((fp = fopen(argv[1], "r")) != NULL) {
		while ((ch = getc(fp)) != EOF) {
			if ((ch >= 'a') && (ch <= 'z'))
				ch += 'A' - 'a';
			putc(ch, stdout);
		}
	}

	return 0;

}
