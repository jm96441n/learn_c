#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("\n Length: %d\n", max);
    int i = 0;
    while((i < MAXLINE) && (longest[i] != '\0')) {
      printf("%c", longest[i]);
      ++i;
    }
    printf("\n");
  }

  return 0;
}

int getLine(char s[], int lim)
{
  int c, i, j;

  i = 0;
  j = 0;
  while((c = getchar()) != EOF && (c != '\n')) {
    if (i < lim - 1) {
      s[i] = c;
      ++i;
    }
    ++j;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return j;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
