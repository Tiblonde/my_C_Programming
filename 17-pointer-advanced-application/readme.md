# 17 pointer and advanced application

In section 11, we talked about how to use pointer points variable as argument to let function change the variable itself. 

In section 12, we talked about how to do arithmetic operation on pointer points element of array. 

In this section, we will talk about the **dynamic memory allocation** and pointer points function.

## 17.1 dynamic memory allocation

In C, data structures are fixed-size, even the flexible array. That maybe introduce problem. C also provides the capacity to allocate memory during the run-time.

**Dynamic memory allocation** can be applied to any type data, but mainly to string, array and structure. This type (dma) can be linked to form format, tree and other data structure.

## 17.1.1 memory allocation function

There are three memory allocation functions in `<stdlib.h>`:
```c
	malloc()	// Allocate memory without initialization
	calloc() 	// Allocate memory and clear memory
	realloc() 	// resize the memory allocated before
```
`malloc()` is often used because it doesn't clear the memory. Since function can't aknowledge the specific data type before alloctating memory, it will return void * type, a general pointer.

When there can't be found the desired memory, function will return NULL pointer:
```c
	/* Testin return value */
	p = malloc(10000);
	if (p == NULL) {
		/* alocation failed; take approprite action */
	}

	/* A commen syntex */
	if ((p = malloc(10000)) == NULL) {
		/* alocation failed; take approprite action */
	}
```

NULL macro is defined in many header, like `<locale.h>, <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>` and `<time.h>`

## 17.2 dynamic allocate string

Dynamic memory allocation is useful for the operation of string. string is stored in character array, and it is hard to predict how long the array need.

	void *malloc(size_t size);

`malloc()` allocate *size* byte memory, and return the pointer points that memory. **size_t** type refers to unsigned integer, and because the sizeof(char) just be 1, so `malloc()` can easily allocate memory for string:

```c
	p = malloc(n + 1)
```
here p is char * type, void * type will auto convert.

```c
	strcpy(p, "abc");
```

Since the memory allocated by `malloc()` are not initiated so we can call `strcpy()` to initiate it.

```c
	/* Allocate memory to concate two string */
	char *concat(const char *s1, const char *s2) {
		char * result;
		
		result = malloc(strlen(s1) + strlen(s2) + 1);
		if (result == NULL) {
			printf("Error: malloc failed in concat\n");
			exit(EXIT_FAILURE);
		}
		strcpy(result, s1);
		strcat(result, s2);
		return result;
	}

	// Usage example
	p = concat("abc", "def");
```

## 17.3 dynamic allocate array

Since string is equivalent to array, it is also benefit to allocate appropriate size for array. `malloc()` can be used for allocate memory for array, and `calloc()` will initiate the memory at the same time. `realloc()` can "expand" or "shrink" the array as needed.

----------<stdio.h> malloc()----------

```c
	/* If the program need a n-size array and n can be
	calculated during the program. */
	int *a;
	...
	a = malloc(n * sizeof(int));
	// Now a becomes array!
```

once a points the dynamic allocated memory, one can ignore the fact that a is a pointer and view it as the name of array:
```c
	a = malloc(n*sizeof(int));
	...
	for (i = 0; i < n; i++)
		a[i] = 0;
```
----------<stdlib.h> calloc()----------

The prototype of calloc() in <stdlib.h> is:

```c
	void *calloc(size_t nmemb, size_t size);	
```

`calloc()` allocates memory for the array with **nmemb** element, in which each element has **size** long bytes. After allocating memory, `calloc()` will automatically initiate by setting all bit zero.

```c
	a = calloc(n, sizeof(int));
```

The prototype of realloc() in <stdlib.h> is:

```c
	void *realloc(void *ptr, size_t size);
```

`realloc()` can adjust the size of array, **ptr** must points the memory that be allocated by `malloc(), calloc()` or `realloc()`. **size** is the new size of array.

## 17.4 release the memory

The memory allocated by `malloc()` and other memory allocation functions come from a memory sink called **heap**. Heap may be exhausted when frequently call these functions, making them return NULL pointer.

As for the program, memory which can't be accessed is called garbage. One program with garbage may exist **memory leak**. Some languages provide garbage collector for locating and recycling garbage, but C doesn't. Each C program takes responsibility of their own garbage, uses `free()` to release the memory.

The prototype of `free()` in `<stdlib.h>` is:

```c
	void free(void *ptr);
```

It is easy to use `free()`: just pass the pointer points the useless memory.

Notice: **dangling pointer** is the phonemenon that free(p) will release memory p points , but p pointer has not been changed.

## 17.5 linked list

Dynamic allocation is useful for the structure of sheet, tree, graph and other linked data-type. **Linked List** is made of a sery of struct, each node has a pointer points to the next node, the last node points to NULL.

### 17.5.1 declare node struct

to build a linked list, we need to declare the node struct firstly:
```c
	struct node {
		int value;
		struct node *next; /* points the next node */
	};
```
Notice next is a struct node pointer, so it can store NULL;

We can make a pointer variable points NULL, that is the end of list points:
```c
	struct node *first = NULL;
```
Next, we want creat more nodes and add them to the linked list, it follows 3 steps:
```
	1. allocate memory for each node
	2. store data into node
	3. inject node into list
``` 
we need another pointer variable for the reture value of allocate() to create new node:
```c
	struct node *new_node;
	// new_node points one memory store struct node
	new_node = allocate(sizeof(struct node));

	// store data into node
	*new_node.value = 10;

	//or we can use -> operator
	new_node->value = 10;
```
the -> operator is designed to access member in struct: `(struct_pointer)->member` is equivalent to `*struct_pointer.member`. It is legal to assign because -> operator generate lvalue. It is also legal to use it in scanf:
```c
	scanf("%d", &new_node->value);
```
Next, we will introduce how to inject node into the beginning of linked list (which is the simplest situation).

As new_node points the node ready for injection and first points the beginning of linked list, we should change member next to let it points the beginning node:
```c
	// now new_node points the end of linked list
	new_node->next = first;
	// let first points the beginning of list back again
	first = new_node;
```
Notice: it is chaos when explaining how to inject first node into a null linked list. Technically speak, new_node always points the memory to store node, which will be injected into list later. And first always points beginning node of list. We assign first to NULL in order for the consistence.

Furthermore, we can make a function to add node into list:
```c
	struct node *add_to_list(struct node *list, int n) {
		struct node *new_node;

		new_node = allocate(sizeof(struct node));
		if (new_node == NULL) {
			printf("error: malloc failed in add_to_list\n");
			exit(EXIT_FAILURE);
		}
		new_node->value = n;
		new_node->next = list;
		return new_node;
	}

	first = add_to_list(first, 10);
	first = add_to_list(first, 20);
```
we can use add_to_list() to create a linked list to store user input:
```c
	struct node *read_numbers(void) {
		struct node *first = NULL;
		int n;

		printf("Enter a series of integers (0 to terminate): ");
		for (;;) {
			scanf("%d", &n);
			if (n == 0)
				return first;
			first = add_to_list(first, n);
		}
	}
```

### 17.5.5 search in linked list

for loop is useful t search in linked list:
```c
	struct node *search_list(struct node *list, int n) {
		struct node *p;

		for (p = list; p!=NULL; p = p->next)
			if (p->value == n)
				return p;
		return NULL;
	}
```

### 17.5.6 delete node from linked list

delete node also follows 3 steps:
```
	1. locate the node to be deleted
	2. change the before node making it pass the node
	3. call free() to delete the memory
```
locate one node to be deleted needs **tracing pointer**, namely second pointer points the before node:
```c
	for (cur = list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next)
		;
```
In such way, we can locate node by cur and the before node by prev, and now we are ready to delete the cur node:
```c
	prev->next = cur->next;
	free(cur);
```
we can also make a function to delete that node:
```c
	struct node *delete_from_list(struct node *list, int n) {
		struct node *cur, *prev;

		for (cur = list, prev = NULL;
			 cur != NULL && cur->value != n) ;
		if (cur == NULL)
			return list;
		if (prev == NULL)
			list = list->next;
		else
			prev->next = cur->next;
		free(cur);
		return list;
	}
```
Notice that if the deleted node is on the beginning and end.

### 17.5.7

We can use the same method to store node in order. The trick is to compare before injection:
```
	inventory2.c
```

## 17.6 pointer points pointer

in chapter 13.7 we have meet the **pointer points pointer**: we created a char * type array, so the pointer points array's element will be `char **` type.

Let's review the function in chapter 17.5:
```c
	struct node *add_to_list(struct node *list, int n) {
		struct node *new_node;

		new_node = malloc(sizeof(struct node));
		if (new_node == NULL) {
			printf("Error: malloc failed in add_to_list.\n");
			exit(EXIT_FAILURE);
		}
		new_node->value = n;
		new_node->next = list;
		return new_node;
	}
```
when we call add_to_list(), we pass the pointer points the beginning of linked list, it will return a pointer points the beginning of new linkde list.

Supposing that we modify the return statement with `list = new_node;`, it actually can't archieve the effect that *change list points the beginning of new linked list*, because list, the pointer variable, receives pointer passed as value:
```c
	add_to_list(first, 10);
	// first (pointer points beginning) can't be changed
```

but if we pass a pointer points first, that will work well:
```c
	void add_to_list(struct node **list, int n) {
		struct node *new_node;

		new_node = malloc(sizeof(struct node));
		if (new_node == NULL) {
			printf("Error: malloc failed in add_to_list.\n");
			exit(EXIT_FAILURE);
		}
		new_node->value = n;
		new_node->next = *list;
		*list = new_node;
	}
```

## 17.7 pointer points function

C allows pointer points function (yes, not constrain to data!). functions also occupy memory, so it is not strange to have a function pointer.

Passing function pointer as argument is very common. Supposing we inplement integrate() to calculate the integration between a and b in function f, so it needs a function pointer argument:
```c
	double integrate(double (*f)(double), double a, double b);
```
`(*f)`, the round brackets represent that f is a function pointer, instead of a function return pointer. Moreover, it is legal to use function declaration:
```c
	double integrate(double f(double), double a, double b);
```

When we call integrate(), it receives function name as the first argument:
```c
	result = integrate(sin, 0.0, PI/2);
```
inside integrate(), we can access function like this:
```c
	y = (*f)(x); /* this is better because f is a function pointer */
	// or this
	y = f(x); 
```
### 17.7.2 qsort()

`<stdlib.h>` provides powerful function qsort() to sort any array. Since array's element can be any type, we should tell qsort() how to determine which element is smaller. So we can make compare() to pass to:
```c
	void qsort(void *base, size_t nmemb, size_t size,
			   int (&compar)(const void *, const void *));
```
**base** points array's first element (just pass the array' name is OK). **nmemb** is the number of elements to be sorted. **size** is the size of each element. **compar** is function pointer points compare().

We find that compare() must have two `void *` argument, so inside function there should be **type conversion** before we can access elements by pointer:
```c
	/* version 1: ordinary*/
	int compare(const void *p, const void *q) {
		const struct part *p1 = p;
		const struct part *q1 = q;

		if (p1->number < q1->number)
			return -1;
		else if (p1->number == q1->number)
			return 0;
		else 
			return 1;
	}

	/* version 2: reduced */
	int compare(const void *p, const void *q) {
		if (((struct part *) p)->number < ((struct part *) q)->number)
			return -1;
		else if (((struct part *) p)->number == ((struct part *) q)->number)
			return 0;
		else 
			return 1;
	}
```

### 17.7.3 function pointer 's other usage

C treats function pointer as data pointer, so we can store function pointer into variable, array, or member in struct or union, even return value.

```c
	/* function pointer that points any function with 
	 * int argument and void return
	 */
	void (*pf)(int);

	pf = f; // f is such function

	/* Once pf points f, we can call f() like: */
	(*pf)(i);
	pf(i);
```

Array with function pointer element is a common usage of function pointer. Supposing that we need to show user the usable command menu, where we implement functions to archieve these commands, so we can store these function pointer into array:
```c
	void (*file_cmd[])(void) = {new_cmd,
								open_cmd,
								close_cmd,
								close_all_cmd,
								save_cmd,
								save_as_cmd,
								exit_cmd};

	// if user enter n (n is integer range from 0 to 6) then one can access that function using index
	(*file_cmd[n])();
