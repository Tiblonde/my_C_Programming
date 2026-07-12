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

Dynamic allocation is useful for the structure of sheet, tree, graph and other linked data-type. Linked List is made of a sery of struct, each node has a pointer points to the next node
