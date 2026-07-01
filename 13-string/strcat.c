char *strcat (char *s1, const char *s2) {
	char *p;

	p = s1;
	while (*p != '\0')
		p++;
	while (*s2 != '\0') {
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';
	return s1;
}

/* a reduced version */
char *strcat (char *s1, const char *s2) {
	char *p = s1;

	while (*p)
		p++;
	while (*p++ = *s2++)
		;
	return s1;
}
