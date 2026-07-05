/* Checks whether a file can be opened for reading */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int i, flag = 0;	

	if (argc < 1) {
		printf("Usage: can't open filename\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++) {
		if((fp = fopen(argv[i], "r")) == NULL){
			printf("%s can't be opened\n", argv[i]);
			flag++;
		} else {
			printf("%s can be opened\n", argv[i]);
		}
		//fclose(fp);
	}

	if (flag)
		exit(EXIT_FAILURE);

	return 0;
}
