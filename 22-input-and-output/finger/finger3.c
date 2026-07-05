#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int i;

	if (argc < 2) {
		printf("Usage: filename\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) != NULL)
	}
}
