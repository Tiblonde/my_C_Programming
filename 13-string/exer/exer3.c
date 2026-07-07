// section 13.3
#include <stdio.h>

int main(void) {
  int i, j;
  char s[10];

  scanf("%d%s%d", &i, s, &j);  // watchout: there is no & with s
  // Please type 12abc34 56def78
  
  printf("i: %d\n", i);
  printf("s: %s\n", s);
  printf("j: %d\n", j);

  return 0;
}