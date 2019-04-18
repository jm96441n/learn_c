#include <stdio.h>
#include <ctype.h>

int lower(int c);

int main()
{
  int a, b, c;
  a = 'A';
  b = 'B';
  c = 'c';
  printf("%c %c %c\n", a, b, c);
  printf("%c, %c, %c\n", lower(a), lower(b), lower(c));
}

int lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
