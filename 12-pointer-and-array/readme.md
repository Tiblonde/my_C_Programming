# 12 pointer and array

## 12.1 the arithmetic operatrion of pointer
```c
	int a[10], *p;
	p = &a[0];
```
the above statement makes pointer p point to array a 's first element. Moveover, we can apply arithmetic operations on pointer.
```c
	/*** pointer plus integer ***/
	int a[10], *p, *q, i;
	p = &a[2];
	q = p + 2; /* pointer copy */
	p += 6;

	/*** pointer minus integer ***/
	p = &a[8];
	q = p - 3;
	p -= 6;

	/*** pointer minus pointer ***/
	p = &a[5];
	q = &a[1];
	i = p - q;
	i = q - p;

	/*** pointer compare ***/
	p = &a[5];
	q = &a[1];
```
## 12.2 pointer for handling with array

Arithmetic supports allow program to access elements in array by adding pointer itself:
```c
	#define N 10
	...
	int a[N], sum, *p;
	...
	sum = 0;
	for (p = &a[0]; p < &a[N]; p++) // &a[N] 
		sum += *p
```
Notice the priority of * and ++ operator:
```c
	*p++ = j;
	*(p++) = j;
```
in that we get:
```c
	while (p < &a[N])
		sum += *p++;
```
We can apply these operations to alter the program in sectin 10.2, where we used a integer top to record the top of stack:
```c
	int *top_ptr = &contents[0];
	...
	void push(int i) {
		if (is_full())
			stack_overflow();
		else
			*top_ptr++ = i;
	}

	int pop(void) {
		if (is_empty()) 
			stack_underflow();
		else
			return *--top_ptr;
	}
```