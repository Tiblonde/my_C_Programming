## 13.1 string literal

string literal is a character sequence rounded by a pair of quote.

### 13.1.2 to expand string literal

If there is no space in one line to put all string literal, one can use "\" at the end, which allows to connect in next line:
	printf("Put a disk in drive A, then \
	press any key to continue\n");
When use \, string literal must continue at the beginning of next line, so it will destroy the indent structure. 

### 13.1.4 the operation of string literal

It is usually to use string literal at any location where C allows to use char *pointer

