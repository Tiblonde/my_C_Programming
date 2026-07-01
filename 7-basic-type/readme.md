## 7.1 integer

Integer is usually stored in a form of 16-bit or 32-bit. In signed integer, the maximum 16-bit integer is 32767 (2e15-1), and the maximum 32-bit integer is 2147483647 (2e31-1). Meanwhile in unsigned integer, the maximum 16-bit integer is 65535 (2e16-1) and the maximum 32-bit integer is 4294967295 (2e32-1).

```c
short int
unsigned short int
int 
unsigned int 
long int 
unsigned long int
```

In <limits.h>, one can find the macro define for each integer type.

### 7.1.1 integer constant

### 7.1.2 read/write integer

The convertion expression `d` only work for `int`.
When one read/write unsigned integer, `u` work for base 10, `o` work for base 8 and `x` work for base 16.
When one read/write short integer, add character `h` in front of `d, o, u, x`.
When one read/write long integer, add character `l`

### 7.1.3 program: sum a series of numbers

## 7.2 float type

Float type can not only save number with dot, but also extreme large or small number, contributing to its floating point.

```c
float
double
long double
```

In <float.h> one can find the macro define for float type.

### 7.2.1 float constant

```c
57.0 57. 57.0e0 57E0 5.7e+1 .57e2 570.e-1
```

The above format are all valid for representing number 57.0
The float constant must has point or e, and e always represent power 10.

The machine will save float constant in form of double.
One can add `F/f` (57.0f) or `L/l` (57.0L) to force.

### 7.2.2 read/write float

The conversion expression `%e, %f, %g` are used for float type. For double and long double, there is slightly difference:
When one need to read double type, place character `l` in front of `e,f,g,`: double d; scanf("%lf", &d);
When one need to read or write long double type, place character `L` in front of `e,f,g`: long double ld; scanf("%Lf", &ld); printf("%Lf", ld);


## 7.3 character type

The most common used character set is ASCII, it use 7-bit to represent 128 characters. In some implement, ASCII is expanded to 8-bit to represent 256 charactors.
Moreover, Unicode is also commonly used, which uses 16-bit to represent 65536 charactors.

### 7.3.1 escape sequence

To input characters which can't be typed from keyboard, C introduces escape sequence.

### 7.3.2 character handle function

The way to turn lowercase to uppercase is not elegant:
```c
if ('a' <= ch && ch <= 'z')
	ch = ch - 'a' + 'A';
```
An more efficient and transplate-friendly way is call toupper function:
```c
#include <ctype.h>

ch = toupper(ch);
```

### 7.3.3 read/write character

Conversion expression enable scanf and printf to operate read/write on one character:
```c
char ch;
scanf("%c", &ch);
printf("%c", ch);
```

When dealing with character, scanf will not skip space character.

C also provide other methods to read/write one character, that are getchar and putchar. When call getchar, it will read one character and return that character.

```c
do {
	scanf("%c", &ch);
} while(ch != '\n');

while ((ch = getchar()) != '\n')
	;

while (getchar() != '\n')
	;
```
### 7.3.4 program: determine the length of a message

