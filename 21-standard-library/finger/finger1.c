#include <stdio.h>
#include <stddef.h>

struct s {
	int a;
	int b[4];
	char c;
};

int main(void) {
	int size, offset;
	// How to get the size of member without struct variable?
	//printf("The size of member a is: %ld\n", sizeof(struct s.a)); /* WRONG */
	struct s numb;
	printf("The size of member a is: %ld\n", sizeof(numb.a));
	printf("The size of member b is: %ld\n", sizeof(numb.b));
	printf("The size of member c is: %ld\n", sizeof(numb.c));

	printf("The offset of member a is: %ld\n", offsetof(struct s, a));
	printf("The offset of member b is: %ld\n", offsetof(struct s, b));
	printf("The offset of member c is: %ld\n", offsetof(struct s, c));
	
	printf("The size of struct s is: %ld\n", sizeof(struct s));

	return 0;
}

/*
 * printf("The size of member a is %ld\n", sizeof(((struct s*)0)->a));
 */
