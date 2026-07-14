# 9 function

## 9.1 define and call function
```
	average.c
	countdown.c
	pun2.c
```
function definition has followed format:
```
	ret_type func_name (parameter) {
		declaration;
		statement;
	}
```
function call is composed by func_name and argument list with round brackets:
```c
	average(x, y);
	print_count(i);
	print_pun();
```
```
	prime.c
```
## 9.2 declare function

in the previous section's program, function definition always be placed before main(). Virtually, C allows to put function definition after main():
```c
	#include <stdio.h>

	int main(void) {
		double x, y, z;

		printf("Enter three numbers: ");
		scanf("%lf %lf %lf", &x, &y, &z);
		printf("Average of %g and %g: %g\n", x, y, average(x, y));

		return 0;
	}

	double average(double a, double b) {
		return (a + b) / 2;
	}
```
when compiler meets average() in main(), it has no information about the funciton: neither parameters nor ret value. But compiler will suppose average() return int type value, and not to report errors.

C provides a method: function declaration, that actually declare function before call it:
```
	ret_type func_name (parameter)
```
in this way, the above program can be modified like:
```c
	#include <stdio.h>
	
	double average(double a, double b);	/* DECLARATION */

	int main(void) {
		double x, y, z;

		printf("Enter three numbers: ");
		scanf("%lf %lf %lf", &x, &y, &z);
		printf("Average of %g and %g: %g\n", x, y, average(x, y));

		return 0;
	}

	double average(double a, double b) {/* DEFINITION */
		return (a + b) / 2;
	}
```
we call the beginning declaration as function prototype. It provides specific information about function: the parameters, ret value type.

We can also reduce the parameter name:
```c
	double average(double, double);	
```

## 9.3 argument

**parameter** occur in function definition, representing expression when call function by fake name; **argument** occur in function call.

Since argument is passed through value: when call function, C will compute the value of each argument and pass the value to the parameters in function definition, so that the change to paramters don't affect the responding argument

But value pass sometimes block some implementation. For example, since C don't allow function return two value, it seems impossible to implement alike function:
```c
void decompose (double x, long int_part, double frac_part) {
	in_part = (long) x;
	frac_part = x - int_part;
}
// that won't work properly
```

### 9.3.1 argument conversion

C allows function call even the argument type don't follow
 the parameter type. argument conversion is handled by compiler:
```
	1. Compiler meet prototypr before calls: It will convert argument to proper parameter type implicitly.
	2. Compiler not meet protype before call: It will execute default argument conversion, that converts float type to double type and converts char/ short to int type.
```

### 9.3.2 array argument
```c
	int f(int a[]) {
		...
	}
```
array always be used as argument. When one-dimension array is used as parameter, one can dismiss the length of the array like above.

But f funciton can't acknowlegde the length of the array (even use sizeof()), so in practice, the length usually be passed as additional parameter:
```c
	int f(int a[]) {
		int len = sizeof(a) / sizeof(a[0]);
		/*** WRONG: not the number of elements in a ***/
	}

	int sum_array(int a[], int n) {
		int i, sum = 0;
	
		for (i = 0; i < n; i++)
			sum += a[i];

		return sum;
	}
```
the practical usage of array argument is: pass the length of array as second argument:
```c
	int sum_array(int a[], int n) {
		int i, sum = 0;

		for (i = 0; i < n; i++)
			sum += a[i];

		return sum;
	}
```
a fact about array argument is that: function can change element of array parameter, and that affect the relevant array argument:
```c
	void store_zeros(int a[], int n) {
		int i;

		for (i = 0; i < n; i++)
			a[i] = 0;
	}

	// store_zeros() will actually store 0 in the first 100 elements of array b.
	store_zeros(b, 100);
```
### 9.3.3 variable array parameter (C99)
```c
	int sum_array(int n, int a[n]); // The order matters!
```

## 9.4 return 

non-void type return value function needs return statement to determinet the return value.

If no expression on the right, it will return void:
```c
	return ; /* return statement in a void function */
```
## 9.5 program termination

Since main() is a function, it must have its return type. Normally, main() return int type:
```c
	int main(void) {

	}
```
Some implementation dismiss the int because compiler will view it as int by default.

Another method to terminate program is exit(). It belongs to `<stdlib.h>` and the usage is equivalent to return.
```c
	exit(0); /* normale termination*/
	return 0;

	/* As 0 is meaningless constant, <stdlib.h> has some 
	 * macro represent the same value
	 */
	exit(EXIT_SUCCESS); // return 0;

	exit(EXIT_FAILURE); // return 1;
```

## 9.6 recursive

Recursive is so cool that some language extremely rely on it. C also implements this feature:
```c
	/* Compute n! using recursive */
	int fact(int n) {
		if (n <= 1)
			return 1;
		else
			return n*fact(n-1);
	}
```
here we introduce an interesting but frastrated at first glance algorithm called quicksort:
```
	qsort.c
```