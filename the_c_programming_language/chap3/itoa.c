#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
  char toa[MAXLINE];
  int n = -2147483648;
  itoa(n, toa);
  printf("%s\n", toa);
  return 0;
}

void itoa(int n, char s[])
{
  int i, sign;

  sign = n;

  i = 0;

  do {
    s[i++] = abs(n % 10) + '0';
  } while (n /= 10);

  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
{
  int i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    s[i] = s[i] ^ s[j];
    s[j] = s[i] ^ s[j];
    s[i] = s[i] ^ s[j];
  }
}
