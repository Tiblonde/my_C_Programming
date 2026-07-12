## 11 pointer

Most mordern computers divide memory into byte (8-bits), each byte has its unique address. (In addition, memory always be mapped into word (4-bytes), but still allocated by byte address)
```c
	int *p;
```
the above sentence is to state one pointer *p* which points to an integer object. pointer variable stores variable's address. In other word, pointer is address.

To get the address of variable, C provide &. That means if x is the variable, then &x is the address of x (the pointer of x). To access the object which pointer points to, C provide *. That means if p is the pointer, then *p is the object which p points to.
```c
	int i, *p; /* Declaration: points nowhere */
	p = &i;	/* Initiation */
```

## 11.3 copy of pointer

C allows to use assign operator (=) to copy pointers:
```c	
	int i, j, *p, *q;
	p = &i;
	q = p; /* Now p and q all points to i */
	*p = 1; /* Assign *p or *q is an equivalent method to assign i*/
	*q = 2;
```

## 11.4 pointer as argument

In section 9.3, function call can't change the variable passed as argument because C will pass value. Here, we stop using variable as argument by using &x as argument, namely pointer points to x.
```c
	void decompose(double x, long *int_part, double *frac_part) {
		*int_part = (long) x;
		*frac_part = x - *int_part;
	}

	/* The prototype of function can be */
	void decompose(double x, long *int_part, double *frac_part);
	void decompose(double, long *, double *);
```
when we call function like: decompose(3.1415, &i, &d), function receives pointers points i and d as argument. During excution, it stores the pointer points to i into int_part.

Not surprisely, scanf() is such a function that receives pointer as argument:
```c
	int i;
	scanf("%d", &i);
```
as we know scanf() receive pointer, it is not illegal to call like below:
```c
	int i, *p;
	p = &i;
	scanf("%d", p);
```
keyword *const* can be used to confine the unchangable object:
```c
	void f(const int *p) { /* const in the parameter */
		*p = 0; /*** WRONG ***/
	}
```
in this case, p is a pointer points a constant integer, so the atempt to change the constant will be illegal.

## 11.5 pointer as return value
```c
	int *max(int *a, int *b) {
		if (*a > *b)
			return a;
		else
			return b;
	}
```
when call max(), two pointer will be passed as argument and the return value is the pointer points to the max of objects.

