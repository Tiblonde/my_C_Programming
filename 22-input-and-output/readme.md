# 22 input and output

This longest chapter will discuss `<stdio.h>` where input/output functions are stored. Since chapter 2, we have already got familiar with printf(), scanf(), putchar(), getchar(), puts(), and gets(). We will provide more information about these functions, like fprintf() is just the file version of printf().

Here are some basic concepts we will introduce: the idea of stream, FILE type, redirection of input and output, and the difference between text and bin file.

## 22.1 stream

The terminology *stream* represent the source of any input or the destination of any output. Most of the programs we had coded before get input from one stream (usually keyboard) and write output to one stream (usually screen).

The idea is some large-scale program may need other streams, some of them represent the file stored in different medium (like disk driver, CD, DVD, and flash), or devices which dont store file (like printer). Terminology file sometimes represent stream.

And functions in `<stdio.h>` can not only handle with file stream but also streams in other format.

### 22.1.1 file pointer

C-lan access stream by using file pointer. Some specific stream have unique standard name.

```c
	FILE *fp1, *fp2;
```

`<stdio.h>` provides three standard streams for us to use without declaration or open or close it:

```c
	stdin	// standard input, from keyboard
	stdout	// standard output, to screen
	stderr	// standard error, to screen
```

`printf(), scanf(), putchar(), getchar(), puts()`, and `gets()` all get input from stdin and write to stdout. By default, stdin represent keyboard and stdout stderr represent screen, but some operation system provides *redirection* to change the default.

```bash
	demo < in.dat // redirection: get input from file instead of keyboard
	demo > out.dat // redirection: write to file instead of screen
	demo >out.dat <in.dat /*** VALID ***/
	demo > out.dat < in.dat /*** VALID ****/
```

### 22.1.3 text and binary file

`<stdio.h>` supports two type of file: text file where one byte represent one character, and binary file where byte can represent beyond characters.

Moreover, text file is divided into several lines. In Windows, the tag in the end of line is `'\x0d'` followed by `'\x0a'`. In UNIX or Maxintosh, the tag is a sole enter symbol.
text file can include an special symbol indicating the end of file. In Windows, the symbol is `'xla'` (Ctrl+Z). Most other operation systems don't have specific file-end-symbol

## 22.2 file operation

Redirection is simple: no need to open file, close file, or operate file. But when program only depends on redirection, it can't control its file, even can't access these files' name. Redirection also can't support program to read/write two file at the same time.

### 22.2.1 open file

```c
	FILE *fopen(const char *filename, const char *mode);
```

`fopen()` opens a file stream. The first argument is the name of file to open. The second argument is *mode string*, indicating the operation on file.

```c
	fp = fopen("in.dat", "r"); /* open in.dat for reading */
```

`fopen()` returns a file pointer, user can store that into a file pointer variable. When program call input function to read from in.dat later, it will need fp to pass argument.

Some mode string for text file:

```
	"r" "w" "a" "r+" "w+" "a+"
```

Some mode string for binary file:

```
	"rb" "wb" "ab" "r+b"/"rb+" "w+b"/"wb+" "a+b/"ab+"
```

Notice: write operation will cover the original content, but append operation will add data behind the file end.

### 22.2.3 close file

```c
	int fclose(FILE *stream);
```

`fclose()` is to close file that no long used. `fclose()` receives file pointer as argument which comes from `fopen()` or `freopen()`. If close, `fclose()` return 0 otherwise return EOF.

```c
	#include <stdio.h>
	#include <stdlib.h>

	#define FILE_NAME "example.dat"

	int main(void) {
		FILE *fp;
	
		fp = fopen(FILE_NAME, "r");
		if (fp == NULL) {
			printf("Can't open %s\n", FILE_NAME);
			exit(EXIT_FAILURE);
		}
		...
		fclose(fp);
		return 0;
	}	
```

### 22.2.4 attach file to opened stream

```c
	FILE *freopen(const char *filename, const char *mode, FILE *stream);
```

`freopen()` will attach a different file to one opened stream. 

```c
	if (freopen("foo", "w", stdout) == NULL) {
		/* error: foo can't be opened */
	}
```

after closint all files that related to stdout (by redirection or former `freopen()`), `freopen()` wil open file "foo" and relate it with stdout.

The return value of `freopen()` usually is the third argument, but it will return NULL when it can't open new file.

### 22.2.5 get filename from command-line

When one program need to open file, here comes a problem: How to pass the filename to the program? It is not convenient to hard-code filename into program. A better solution is to let the program get filename from command-line.

```c
	int main(int argc, char *argv[]) {}
```

in chapter 13.7, we have known how to define the above `main()` to access command-line parameters, where argc is the number of parameters and argv is a pointer array points to parameter string. `argv[0]` points to the name of the program, so `argv[1]` to `argv[argc-1]` point to remaining parameters and `argv[argc]` is NULL.

```
	canopen.c
```
22.2.6 temporary file

```c
	FILE *tmpfile(void);
	char *tmpnam(char *s);
```

`tmpfile()` create a temporary file (mode="wb+") terminated by closing or program termination. `tmpfile()` return file pointer which is used for accessing that file.

```c
	FILE *tempptr;
	...
	temppter = tmpfile();
```

`tmpfile()` has two problems: 
1. can't get the filename of that tempfile 
2. can't make it eternal. 

If in above situations, we can use `fopen()` to create tempfile. Moreover, `<stdio.h>` provides `tmpnam()` to generate an unique filename.

```c
	char *filename;
	filename = tmpnam(NULL);

	char filename[L_tmpname];
	tmpnam(filename);
```

if `tmpname()` receive NULL, it will store filename into a static variable and return the pointer points to it. If `tmpname()` receive char array, it will return the pointer points to the first character. `L_tmpname` is a macro defined in `<stdio.h>`

### 22.2.7 file buffer

```c
	int fflush(FILE *stream);
	void setbuf(FILE *stream, char *buf);
	int setvbuf(FILE *stream, char *buf, int mode, size_t size);
```

Frequently readout or writein to disk driver tend to be slow. A better way for getting performance is *buffering*: store data that writein stream into buffer zone of memory: When buffer is full, *flush* the buffer area (writein actual output device). 

functions in `<stdio.h>` will auto buffer when buffer is available. It happens background. But under very few conditions, we will actively operate, so `fflush(), setbuf(),` and `setvbuf()` come to help.

When program writes data into file, data usually be stored into buffer. When buffer is full or the program is terminated, buffer will automatically flush. But we can use `fflush()` to archieve manually flush:

```c
	fflush(fp); /* flushes buffer for fp */
wil flush buffer for fp (file related to it)

	fflush(NULL); /* flushes all buffers */
will flush all stream.
```

`setvbuf()` is to change the method to flush buffer and control the size and location of buffer area. The third argument indicates the expected buffer type:

```c
	_IOFBF /* Full buffer: empty readin from stream, full writein to stream */
	_IOLBF /* Line buffer: everty read one line from stream or write one line into stream */
	_IONBF /* No buffer: directly readin or writein without buffer */
```

the second argument of `setvbuf()` is the expected address for buffer. The last argument is the number of byte for buffer.

```c
	char buffer[N];
	...
	setvbuf(stream, buffer, _IOFBF, N);
```

`sefbuf()` is a early-version function, it can set the default value for buffer mode and size of buffer. If buf is NULL, then:

```c
	setbuf(stream, buf);
	(void) setvbuf(stream, NULL, _IONBF, 0);
```

otherwise:

```c
	setbuf(stream, buf);
	(void) setvbuf(stream, buf, __IOFBF, BUFSIZE);
```

`BUFSIZE` is macro. `setbuf()` is old function, so not recommendate.

### 22.2.8 other file operations

```c
	int remove(const char *filename);
	int rename(const char *old, const char *new);
```

`remove()` and `rename()` archieve basic file management. Specially, these two functions receive filename instead of file pointer.

```c
	remove("foo");
```

remove closed file! The temporary file created by `fopen()` can be removed by remove().

```c
	rename("foo", "bar");
```

The temporary file created by `fopen()` can be renamed if one want it to be eternal.

## 22.3 formatted input/output

```c
	int fprintf(FILE *stream, const char *format, ...);
	inr printf(const char *format, ...);
```

`fprintf()` and `printf()` write variable data into output stream, and the format is controlled by format string (second argument). *...* represents variable arguments.

`printf()` is equivalent to `fprintf()` write into stdout:

```c
	printf("Total: %d\n", total);		/* writes to stdout */
	fprintf(fp, "Total: %d\n", total); 	/* writes to fp */
```

### 22.3.2 ...printf conversion

`printf()` and `fprintf()` ask for format string consist of normal characters and conversion indicator, which is made of % and max to 5 optionals:

```
	%|#0|12|.5|L|g

	flag(#0, optional):
		- : left align
		+ : add sign(+/-) for signed number
		  : (space)
		# : 
		0 : padding with 0
	min width(12, optional):
		default right align. If number too small, padding with space.
	precision(.5, optional):
		depend on conversion. 
	length description*(L, optional):
		$hd for short int, %ld for long int
	conversion(g, must):
```

### 22.3.4 ...printf conversion example

### 22.3.5 ...scanf()

```c
	int fscanf(FILE *stream, const char *format, ...);
	int scanf(const char *format, ...);
```

`fscanf()` and `scanf()` read data from input stream, use format string to indicate the format of input.

`scanf()` is equivalent to `fscanf()` read data from stdin:

```c
	scanf("%d%d", &i, &j); 		/* reads from stdin */
	fscanf(fp, "%d%d", &i, &j);	/* reads from fp */
```

### 22.3.6 ...scanf format string

### 22.3.7 ...scanf conversion

scanf conversion is simpler than prinf conversion:

```
	%|*|5|l|d

	*(optional):
		* means assignment suppression: read this data but won't assign it to		object.
	max width(optional):
		restrict the number of character read.
	length description(optional):
		
	conversion:
```

### 22.3.10 check the end of file and error condition

```c
	void clearerr(FILE *stream);
	int feof(FILE *stream);
	int ferror(FILE *stream);
```

If require scanf to read and store n element, it will return n; If the return value is lower than n, that must be error:

```
	file end: it encounters file end.
	read error: it can't read character from stream.
	match fail: the data format is wrong.
```

Every stream has two error type indicator: error indicator and end-of-file indicator. Once set these indicators, it will keep these flags until it is manually cleared:

```c
	eof = feof(fp);
	err = ferror(fp);
	clearerr(fp); /* clears eof and error indicators for fp */
```

Let's code one function to search lines started with integer and return that integer. If something wrong (can't open file; no such line started with integer), return a error code:

```c
	int find_int(const char *filename) {
		FILE *fp = fopen(filename, "r");
		int n;

		if (fp==NULL)
			return -1; 	/* can't open file */

		while (fscanf(fp, "%d", &n) != 1) {
			if (ferror(fp)) {
				fclose(fp);
				return -2; /* input error */
			}
			if (feof(fp)) {
				fclose(fp);
				return -3;	/* integer not found */
			}
			fscanf(fp, "%*[^\n]"); /* skips rest of line */
		}

		fclose(fp);
		return n;
	}
```

Notice: the conversion: `%*[^\n]` will skip rest of line till next `\n`

## 22.4 character input/output

Notice: in this section, functions take characters as int type instead of char type, one of reasons is to return a negative value to indicate the end of file.

### 22.4.1 output functions

```c
	int fputc(int c, FILE *stream);
	int putc(int c, FILE *stream);
	int putchar(int c);
```

`putchar()` writes one character into stdout; `fputc()` and `putc()` write one character into any stream. `putc()` works as same as `fputc()`, but `putc()` usually be archieved through macro and `fputc()` is archieved by function, `putchar()` often be defined as macro:

```c
	#define putchar(c) putc((c), stdout)
```

### 22.4.2 input functions

```c
	int fgetc(FILE *stream);
	int getc(FILE *stream);
	int getchar(void);
	int ungetc(int c, FILE *stream);
```

`getchar()` reads one character from stdin. `fgetc()` and `getc()` read one character from any stream.

`getc()` and `fgetc()` and `getchar()` have simular relations like putc:

```c
	#define getchar(c) getc(stdin)
```

`putc()` and `getc()` are the privilege for programmers because of the speed. `fputc()` and `fgetc()` are the backup

`ungetc()` put the character read from stream back and clear the end-of-file indicator. This will be helpful if it need to read one more character during input. For example, to read a sery of number and stop at the first non-number character:

```c
	while(isdigit(ch = getc(fp))) {
		...
	}
	ungetc(ch, fp); 	/* pushes back last character read */
```

```
	fcopy.c
```
## 22.5 line input/output

### 22.5.1 output functions

```c
	int fputs(const char *s, FILE *stream);
	int puts(const char *s);
```

in chapter 13.3, we had met `puts()`, it writes string into stdout:

```c
	puts("Hi, there!");
```

it will always put a '\n' at the end.

`fputs()` is a general version to write line into any stream, but it won't add `'\n'` at the end.

### 22.5.2 input functions

```c
	char *fgets(char *s, int n, FILE *stream);
	char *gets(char *s);
```

in chapter 13.3, we had met `gets()`, it reads one line from stdin:

```c
	gets(str);
```

it will character-wise read and store into array until it meets `'\n'` (drop `'\n'`).

`fgets()` is a general version to read line from any stream, it is safer than `gets()` because it will restrict the number to readin:

```c
	fgets(str, sizeof(str), fp);
```

it will store `'\n'` if it not reach sizeof(str) - 1.

## 22.6 block input/output

```c
	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

`fread()` and `fwrite()` can read/write big data block in one time. They are mainly used for binary stream although can be carefully transformed to handle text stream.

`fwrite()` copies array in memory to stream. ptr is the address of array, size is the size of each element in that array, nmemb is the number of element to write:

```c
	fwrite(a, sizeof(a[0]), sizeof(a)/sizeof(a[0]), fp);
```

it returns the number of element actually write.

`fread()` read element of array from stream:

```c
	n = fread(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
```

it returns the number of element actually read.

## 22.7 file location

```c
	int fgetpos(FILE *stream, fpos_t *pos);
	int fseek(FILE *stream, long int offset, int whence);
	int fsetpos(FILE *stream, const fpos_t *pos);
	long int ftell(FILE *stream);
	void rewind(FILE *stream);
```

Every stream has a related *file position*. When open file, it will set file position at the beginning of the file (or end of file if mode="a"). Then during read/write, file position will ascend automatically.

But sometimes we also need file position jump to other position.

`fseek()` changes file position in *stream* to *offset*, *whence* is the base:

```
	SEEK_SET: the begin of file
	SEEK_CUR: the current position of file
	SEEK_END: the end of file
```

the second argument is counted on byte, and maybe negative:

```c
	fseek(fp, 0L, SEEK_SET); /* moves to beginning of file */
	fseek(fp, 0L, SEEK_END); /* moves to end of file */
	fseek(fp, -10L, SEEK_CUR); /* moves back 10 bytes */
```

`ftell()` return current file opsition in long int type. It is mainly used for `fseek()`:

```c
	long file_pos;
	...
	file_pos = ftell(fp);	/* saves current position */
	...
	fseek(fp, file_pos, SEEK_SET) /* returns to old postion */
```

`rewind()` sets file position at the beginning, so it is almost `fseek(fp, 0, SEEK_SET)`.

`fseek()` and `ftell()` can only work on long int type file position. For extremely large file, `fgetpos()` and `fsetpos()` will help, because they use fpos_t type to represent file position.

`fgetpos(fp, &file_pos)` stores file position into file_pos. `fsetpos(fp, &file_pos)` set file position for fp.

```
	invclear.c
```

## 22.8 character string input/output

functions in this section have no relations with stream or file. In constract, they allow us to **view string as stream to read/write**. `sprintf()` and `snprintf()` write characters to string like write into stream.

### 22.8.1 output functions

```c
	int sprintf(char *s, const char *format, ...);
	int snprintf(char *s, size_t n, const char *format, ...);
```

`sprintf()` is similar to `printf()` and `fprintf()`, the difference is `sprintf()` write output into character array instead of stream.

```c
	sprintf(date, "%d/%d/%d", 9, 20, 2010);
```

will write `"9/20/2010"` into date and add `'\0'` in the end. It returns the number of stored characters (not include `'\0'`).

`snprintf()` is as same as `sprintf()`, but it restrict the write number.

```c
	snprintf(name, 13, "%s, %s", "Einstein", "Albert");
```

will write `"Einstein, Al"` into name.

### 22.8.2 input functions

```c
	int sscanf(const char *s, const char *format, ...);
```

`sscanf()` is similar to `scanf()` and `fscanf()`, the difference is `sscanf()` read from string instead of file.

```c
	fgets(str, sizeof(str), stdin);	/* read a line of input */
	sscanf(str, "%d%d", &i, &j);	/* extract two integers */
```

Because `sscanf()` read from static data, it is easy for multi-check:

```c
	if (sscanf(str, "%d /%d /%d", &month, &day, &year) == 3)
		printf("Month: %d, day: &d, year: &d\n", month, day, year);
	else if (sscanf(str, "%d -%d -%d", &month, &day, &year) == 3)
		printf("Month: %d, day: &d, year: &d\n", month, day, year);
	else
		printf("Date not in the proper form\n");
```

