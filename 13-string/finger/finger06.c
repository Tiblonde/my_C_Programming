/* Checks planet names */

/* Add strcmplower(), which will return 0 if two string (ignore) 
 * are equal.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int strcmplower(char *string1, char *string2);

int main (int argc, char *argv[]) {
	char *planets[] = {"Mercury", "Venus", "Earth",
					   "Mars", "Jupiter", "Saturn",
					   "Uranus", "Neptune", "Pluto"};

	int i, j;
	for (i = 1; i < argc; i++) {
		for (j = 0; j < NUM_PLANETS; j++)
			if (strcmplower(argv[i], planets[j]) == 0) {
				printf("%s is planet %d\n", argv[i], j+1);
				break;
			}
		if (j == NUM_PLANETS)	
			printf("%s is not a planet\n", argv[i]);
	}

	return 0;
}

int strcmplower(char *string1, char *string2) {
	for (;*string1 != '\0' && *string2 != '\0'; string1++, string2++)
		if (tolower(*string1) != tolower(*string2))
			return 1;

	return 0;
}