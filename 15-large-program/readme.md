# 15 large program

Program is made of multiple source files, and usually some header file. source files contain function definition and external variable.

## 15.1 source file

We can divide program into any source file, with expansion name `.c`. One of the source file must have function named main.

## 15.2 header file

How function in one source file call another function in other source file? or access external variable? or share one macro or typr definiton with another file? The solution is #include command.

header file has expansion name `.h`

### 15.2.1 #include command

```c
	#include <filename> // use C-lib header file
	#include "filename" // use other header file
```

the difference is `<>` will search where system header fill locate, like /usr/include, `""` will search current category and then search system header file loacate.

```c
	#include identifier 
```

is useful for macro define header file name without hardcode:

```c
	#if defined(IA32)
		#define CPU_FILE "ia32.h"
	#elif defined(IA64)
		#define CPU_FILE "ia64.h"
	#elif defined(AMD64)
		$define CPU_FILE "amd64.h"
	#endif 

	#include CPU_FILE
```

### 15.2.2 share macro definition and type definition

Large program need to share *macro definition* and *type definition* by some source file, which are put into header file.

### 15.2.3 share function prototype

If source file1 contains call function f, which iss defined in anther file ffoo.c. It is dangerous to call funciton without declaration, because compiler will suppose function f has int type return value, and suppose the parameters are matched with arguments. And since compiler compile file one at a time, there is no way to check these suppose.

The solution is put the prototype of function f in one header file, and include this header as long as call function f. More importantly, one should include this header in the source file where function is defined, so that compiler can verify if the prototype matches the definition.

```
	"stack.h"			*	calc.c				*	stack.c
	int is_empty(void);	*	#include "stack.h"	*	#include "stack.h"
	int is_full(void);	*	int main(void) {	*	int top = 0;
	void push(int i);	*		make_empty();	*	void make_empty(void) {}
	int pop(void);		*	}					*	int is_empty(void) {}
						*						*	void push(int i) {}
						*						* 	int pop(void) {}
```

### 15.2.4 share variable declaration

extern variable (section 10.2)

