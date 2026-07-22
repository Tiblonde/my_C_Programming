# 10 program structure

In chapter 9, we have introduced function, so we will talk about some questions when one program contains multiple functions.

## 10.1 local variable

variable declared in the function body are **local variable** of that function:

```c
int sum_digits(int n)
{
    int sum = 0; /* local variable */
    while (n > 0) {
        sum += n %10；
        n /= 10;
    }
    return sum;
}
```

In this function, `sum`is local variable.

By default, local variable has these properties:

+ auto storage duration. that means the memory is automatically allocated for the variable when the function is called, and automatically freed when the function returns.

+ block scope. 

### 10.1.1 static local variable

Add `static`before the declaration of local variable will change auto storage duration into static storage duration. That means the variable will have eternal memory cell:

```c
void f(void)
{
    static int i; /* static local variable */
    ...
}
```

now variable`i` has static storage duration, so it has immutable memory. In that case, when f returns, variable `i` still hold its value.

Moreover, static local variable has block scope, so other funcitons can't access it.

### 10.1.2 formal parameter

**formal parameter** has the same properties as local variable (auto duration, block scope). The only difference is that formal parameter will automatically be initiated every time it is called.

## 10.2 external variable

There is another way to pass argument to function besides formal parameter, that is through **external variable**.

external variable is declared aside functions, it has different properties than local variable:

+ static storage duration.

+ file scope. That means all functions behind the external variable declaration can access it.

### 10.2.1 example: stack implementation through external variable

**stack** is a array-like data structure that can store multiple element with same data type. But we can't index it or assign arbitary elements like array, it has finite stack operations:  **push** will store data into stack, and **pop** will access the data on the top.

One stack implementation is through external array. We declare array `contents` , and variable `top` to tag the postion of stack top. `top == 0` when stack is empty. To push data into stack is to store data into `contents[top++]`. To pop data out is to `contents[top--]`.

```c
#include <stdbool.h>
#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}
```

### 10.2.2 the pros and cons of external variable

In most cases, it is recommended for functions to communicate with each other through formal parameters instead of external variable, the main reasons are followed:

+ During the mantainment, if external variable is changed, then one should examine all functions refer that variable.

+ If external variable is assigned wrong value, it is hard to determine the function that goes wrong.

+ It is hard to reuse those functions relying on external variable in other program.

A benefitial pratice is to use meaningful name when declare external variable. If it is too common (like `i`or`tmp`), it maybe used as local variable.

```
guess.c
```


