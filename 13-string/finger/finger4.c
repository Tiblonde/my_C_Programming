/* reverse.c */
#include <stdio.h>

int main(int argc, char * argv[]) {
	// pointer (variable) can increment
	// array name is pointer
	// but array name is just rvalue
	// so argv can't increment
	int i;
	for (i = argv - 1; i > 0; i--)
		printf("%s ", *argv[i]);

	return 0;
}