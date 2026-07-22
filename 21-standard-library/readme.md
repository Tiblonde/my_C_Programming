# 21 standard library

## 21.1 the use of standard library

C89 standard library is divided into 15 parts, each part is described by a header, some of them are listed:

```
<stdio.h> <stdlib.h> <string.h> <time.h> <limits.h>...
```

standard headers are mainly consisted with function prototype, type definition and macro definition.

### 21.1.2 functions hidden by macro

C programmer often use macro with parameters to substitute small functions, this practise is common in standard library.

`getchar()` is declared in `<stdio.h>`:

```c
	int getchar(void); /* Prototype */
```

meanwhile, `<stdio.h>` usually define `getchar()` as a macro:

```c
	#define getchar() getc(stdio)
```

by default, compiler will view it as a macro call when program calls `getchar()`.

## 21.2 Introduction to C89 standard library

`<assert.h>`: only include macro assert(), it allows user to self-check in the program.

`<ctype.h>`: character handler; provides functions about classification and case-convertion.

`<errno.h>`: error; provides errno (error number), which is a lvalue and can be detected after calling to check whether error happens.

`<float.h>`: float type property; provides macro about properties of float type, like the range of float and the precision of float.

`<limits.h>`: the size of int type; provides macro about properties of int type, like the range of int (max and min)

`<locale.h>`: localization;

`<math.h>`: mathmatic computation; provides common math functions.

`<setjmp.h>`: unlocal jumpl; provides setjmp() and longjmp(). Mainly handle with serious problem during execution.

`<signal.h>`: signal handler; provides functions to handle with abnormal situation, including interrupt and runtime error.

`<stdarg.h>`: variable argument; provides some tools for coding functions with variable arguments, like printf() and scanf().

`<stddef.h>`: common definition; provides definitions about common type and macro.

`<stdio.h>`: input/output; provides sevaral input/output functions.

`<stdlib.h>`: provides lots of functions which can't be included into other headers. Like functions which can convert string into number, generate random number, allocate memory, communicate with os, search and sort, et.

`<string.h>`: string handler; provides string operations like copy, concat, compare and search, and operations on any memory block.

`<time.h>`: date and time; provides functions to get time (and date), manipulate the expression of time and date.

## 21.4 <stddef.h>

```c
	ptrdiff_t // the result type for pointer substraction
	size_t // the return type for sizeof operator
	wchar_t // a type which is large enough to express all characters
```

all above types are int type, ptrdiff_t is signed and size_t is unsigned.

```c
	NULL // a macro for null pointer
	offsetof // a macro for calculating the byte number between the beginning of one structure to one of its element.
```

`offsetof()` needs two parameters: struct type and member indicator.

```c
	struct s {
		char a;
		int b[2];
		float c;
	};
```

the value of `offsetof(struct s, a)`; must be 0.

