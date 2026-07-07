// section 13.3
#include <stdio.h>
#include <ctype.h>

int read_line(char s[], int n);

int main(void) {
  char s[10];
  int n;

  n = read_line(s, sizeof(s)/sizeof(s[0]));
  
  puts(s);
  return 0;
}

/* version 1
int read_line(char s[], int n) {
  int i = 0;
  char ch;

  while((ch = getchar()) != '\n') {
    if (i < n)
      s[i++] = ch;
  }
  s[i] = '\0'
  return i;
}
*/

int read_line(char s[], int n) {
  int i = 0, flag = 0;
  char ch;

  while((ch = getchar()) != '\n') { // c. encounter '\n'
    if ( ch != ' ' && flag == 0)
      flag = 1;
    if ( ch == ' ' && flag == 1) { // b. encounter ' '
      break;
    }
    if (flag == 1 && i < n) // a. skip space
      s[i++] = ch;
  }
  s[i] = '\0'
  return i;
}