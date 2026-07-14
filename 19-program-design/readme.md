# 19 program design

Actually, programs can be much bigger than we realize.(some of them are more than hundred thousand lines). C is not designed for large program especially but some of them are made of C.

## 19.1 module

It is practical to view one program as seperate modules. module is collection of sery of services, some of them can be used by other client (other parts of the program). Each module has one interface to describe services it provides.

"Service" is just function. "Interface of module" is header file, it contains function prototype that can be used by other file in the program. "Implementation of module" is the source file which contains function definition in these module.

we can divide the calculator program in chapter 15 into such structure: 
```
	calc.c (source file) contains main()
	Stack Module is stored in stack.h and stack.c

	So stack.h is the interface of Stack module, and stack.c is the implementation of Stack Module.
```

Module division brings advantages like: abstraction, reusability, maintainess.

### 19.1.1 cohesion and coupling

a good module interface should have highly cohesion and low coupling.

### 19.1.2 the type of module

to archieven highly cohesion and low coupling, module can be sorted as:
```
	1.data pool: the collection of relevant variable or constant. `<float.h>` and `<limits.h>` are such type
	2.library: the collection of relevant functions. `<string.h>` is the interface of sting handler functions 
	3.abstraction object: the collection of functions operating on hidden data structure.
	4.abstraction data type: ADT is a hidden implementation of data type. Client module can declare variable using these type but never know how these data type implement. If client need to operate on ADT, it must use functions provided by ADT module.
```

## 19.2 hidden information

A good module often hide some information to its client. For example, clients of stack module shouldn't know whether stack is implemented by array, linked list, or other type.

C provides store type static to hide information. 

### stack module

let's implement stack module using two data type. First, we define the interface like:
```c
	/* stack.h */
	#ifndef STACK_H
	#define STACK_H
	
	#include <stdbool.h>

	void make_empty(void);
	bool is_empty(void);
	bool is_full(void);
	void push(int i);
	int pop (void);

	#endif
```
first we use array implementation:
```c
	/* stack1.c */
	#include <stdio.h>
	#include <stdlib.h>
	#include "stack.h"

	#define STACK_SIZE 100

	static int contents[STACK_SIZE];
	static int top = 0;

	static void terminate(const char *message) {
		printf("%s\n", message);
		exit(EXIT_FAILURE);
	}

	void make_empty(void) {
		top = 0;
	}

	bool is_empty(void) {
		return top == 0;
	}

	bool is_full(void) {
		return top == STACK_SIZE;
	}

	void push(int i) {
		if (is_full())
			terminate("Error in push: stack is full.");
		contents[top++] = i;
	}

	int pop(void) {
		if (is_empty())
			terminate("Error in pop: stack is empty.");
		return contents[--top];
	}
```
Next use linked list to implement:
```c
	/* stack2.c */
	#include <stdio.h>
	#include <stdlib.h>
	#include "stack.h"

	struct node {
		int data;
		struct node * next;
	};

	static struct node *top = NULL;

	static void terminate(const char *message) {
		printf("%s\n", message);
		exit(EXIT_FAILURE);
	}

	void make_empty(void) {
		while(!is_empty())
			pop();
	}

	bool is_empty(void) {
		return top == NULL;
	}

	bool is_full(void) {
		return false;
	}

	void push(int i) {
		struct node *new_node = malloc(sizeof(struct node));
		if (new_node == NULL)
			terminate("Error in push: stack is full.");
		new_node->data = i;
		new_node->next = top;
		top = new_node;
	}

	int pop(void) {
		struct node *old_top;
		int i;

		if (is_empty())
			terminate("Error in pop: stack is empty.");

		old_top = top;
		i = top->data;
		top = top->next;
		free(old_top);
		return i;
	}
```

## 19.3 Abstraction Data Type

Module with abstraction object can't have multi-copy of that object. To archieve this, we should further create abstraction data type.

Once define type Stack, we can own any stack as we can:
```c
	Stack s1, s2;
	make_empty(&s1);
	make_empty(&s2);
	push(&s1, 1);
	push(&s2, 2);
```
We don't know how s1 and s2 are implemented. For stack module's client, s1 and s2 are abstraction and they only respond to specific operation: make_empty(), is_empty(), push(), pop()
```c
	/* stack1.h */
	#ifndef STACK_H
	#define STACK_H
	
	#include <stdbool.h>

	#define STACK_SIZE 100

	typedef struct {
		int contents[STACK_SIZE];
		int top;
	} Stack;

	void make_empty(Stack *s);
	bool is_empty(const Stack *s);
	bool is_full(const Stack *s);
	void push(Stack *s, int i);
	int pop (Stack *s);

	#endif
```

### 19.3.1 encapsulation

Unfortunately, Stack type is not ADT, because `<stack.h>` exposes the implementation of Stack type, so that client can directly use it as struct.

We need encapsulate Stack type. C supports less.

### 19.3.2 imcomplete type

C only provides **imcomplete type** to encapsulate. imcomplete type is: describe the object but lack of object size for definition.

```c
	struct t; /* incomplete declaration of t */
```
here C tells compiler that t is a struct tag, but it doesn't describe its members. It is illegal to use it to declare variable, but sufficient to typedef a incomplete type pointer:
```c
	struct t s; /***WROGNG***/

	typedef struct t *T;
``` 
now type T is pointer points struct t. And now we can declare type T variable (pointer variable), but at this moment, we can't use -> operator since compiler don't know members inside struct t.

## 19.4 stack ADT

ADT is encapsulated by incomplete type.

first we need one header file to define stack ADT and give all stack operation function prototypes:
```c
	/* stackADT.h */
	#ifndef STACKADT_H
	#define STACKADT_H
	
	#include <stdbool.h>

	typedef struct stack_type *Stack;

	Stack create(void);
	void destroy(Stack s);
	void make_empty(Stack s);
	bool is_empty(Stack s);
	bool is_full(Stack s);
	void push(Stack s, int t);
	void pop(Stack s);

	#endif
```
Clients include stackADT.h can declare Stack type variable, a pointer points stack_type struct. But they can't access its members, because they are defined in other file.

```c
	/* stackclient.c */
	#include <stdio.h>
	#include "stackADT.h"
	
	int main(void) {
		Stack s1, s2;
		int n;
	
		s1 = create();
		s2 = create();
	
		push(s1, 1);
		push(s1, 2);
	
		n = pop(s1);
		printf("Popped %d from s1\n", n);
		push(s2, n);
		n = pop(s1);
		printf("Popped %d from s1\n", n);
		push(s2, n);
	
		destroy(s1);
	
		while (!is_empty(s2))
			printf("Popped %d from s2\m", pop(s2));
	
		push(s2, 3);
		make_empty(s2);
		if (is_empty(s2))
			printf("s2 is empty\n");
		else
			printf("s2 is not empty\n");
	
		destroy(s2);
	
		return 0;
	} 
```

### 19.4.2 stack ADT: array

```c
	/* stackADT.c */
	#include <stdio.h>
	#include <stdlib.h>
	#include <stackADT.h>

	#define STACK_SIZE 100

	struct stack_type {
		int contents[STACK_SIZE];
		int top;
	};

	static void terminate (const char *msg) {
		printf("%s\n", msg);
		exit(EXIT_FAILURE);
	}

	Stack create(void) {
		Stack s = malloc(sizeof(struct stack_type));
		if (s == NULL)
			terminate("Error in create: stack could not be created");
		s->top = 0;
		return s;
	}

	void destroy(Stack s) {
		free(s);
	}

	void make_empty(Stack s) {
		s->top = 0;
	}

	bool is_empty(Stack s) {
		return s->top == 0;
	}

	bool is_full(Stack s) {
		return s->top == STACK_SIZE;
	}

	void push(Stack s, int i) {
		if (is_full(s))
			terminate("Error in push: stack is full.");
		s->contents[s->top++] = i;
	}

	int pop(Stack s) {
		if (is_empty(s))
			terminate("Error in pop: stack is empty.");
		return s->contents[--s->top];
	}
```

### 19.4.4 improved: change array type

```c
	/* stackADT.h */
	#ifndef STACKADT_H
	#define STACKADT_H
	
	#include <stdbool.h>

	typedef int Item; /* use Item to represent type */

	typedef struct stack_type *Stack;

	Stack create(void);
	void destroy(Stack s);
	void make_empty(Stack s);
	bool is_empty(Stack s);
	bool is_full(Stack s);
	void push(Stack s, Item t);
	Item pop(Stack s);

	#endif
```
