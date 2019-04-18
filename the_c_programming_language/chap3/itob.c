#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
  char line[MAXLINE];
  int a = 8;
  itob(a, line, 16);
  printf("%s\n", line);
  int b = 36;
  itob(b, line, 16);
  printf("%s\n", line);
  return 0;
}

void itob(int n, char s[], int b)
{
  int i = 0;
  int result;
  do {
    result = abs(n % b); 
    if (result < 10) {
      s[i++] = result + '0';
    } else {
      s[i++] = result + '7';
    }
  } while (n /= b);
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

