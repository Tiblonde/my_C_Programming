// section 13.3
#include <stdio.h>

int main(void) {
  char *p = "abc";
  
  // These function calls maybe wrong
  putchar(p);  // illegal: argument 1 int
  //putchar(*p); // legal
  //puts(p);  // legal
  //puts(*p); // illegal: argument 1 char *

  return 0;
}