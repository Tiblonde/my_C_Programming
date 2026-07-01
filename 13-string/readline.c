
int read_line(char str[], int n) {
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;

	str[i] = '\0';
	return i;
}

int count_spaces(const char s[]) {  // const means the function will not alter
	int count = 0, i;				// string.

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == ' ')
			count++;
		return count;
}

/* count spaces (pointer version) */
count_spaces;
int count_spaces(const char *s) {	// const is to prevent the alternation of 
	int count = 0;					// the character s points to instead of 
									// the s pointer itself.
	for (; *s != '\0'; s++)
		if (*s == ' ')
			count++;
		return count;
}

/* Copy, compare, concentrate, truncate */
#include <string.h> 

char *strcpy (char *s1, const char *s2); // s2->s1

str1 = "abcd"; // wrong
strcpy(str1, "abcd");

char *strcat (char *s1, const char *s2); // cat s2-> end of s1

int strcmp (const char *s1, const char *s2); // < = > 0

size_t strlen (const char *s); 
