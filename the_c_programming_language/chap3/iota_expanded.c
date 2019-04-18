#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[], int padding);
void padString(int n, char s[]);
void reverse(char s[]);

int main()
{
  char toa[MAXLINE];
  int n = 10;
  itoa(n, toa, 1);
  printf("%s\n", toa);
  return 0;
}

void itoa(int n, char s[], int padding)
{
  int i, sign;

  sign = n;

  i = 0;

  do {
    s[i++] = abs(n % 10) + '0';
  } while (n /= 10);

  if (sign < 0) {
    padString(padding - 1, s);
    i = strlen(s);
    s[i++] = '-';
  } else {
    padString(padding, s);
    i = strlen(s);
  }
  s[i] = '\0';
  reverse(s);
}

void padString(int n, char s[]) {
  for(int i = strlen(s); strlen(s) < n; ++i) {
    s[i] = '0';
  }
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
