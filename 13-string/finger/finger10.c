#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_name(char *name);

int main(void) {
	int flag = 0;
	char ch, fn;

	char name[99];
	printf("Enter a first and last name: ");
	gets(name);
	reverse_name(name);
	
	printf("%s\n", name);
	
	return 0;
}


/* 
 * Method 1: sscanf() puts two separated string into two array
 * then sprintf() combine the two array into original array.
 */
void reverse_name(char *name) {
	char first_name[50], last_name[50];
	sscanf(name, "%s %s", first_name, last_name);
	sprintf(name, "%s, %c", last_name, toupper(first_name[0]));
}