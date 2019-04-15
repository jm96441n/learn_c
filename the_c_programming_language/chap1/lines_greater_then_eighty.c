#include <stdio.h>
#define MINLINE 80
#define MAXLINE 10000

int getLineLength(char line[], int lim);

main()
{
  int currentLength;
  char line[MAXLINE];

  while((currentLength = getLineLength(line, MAXLINE)) > 0) {
    if (currentLength > MINLINE) {
      printf("%s", line);
    }
  }

  return 0;
}

int getLineLength(char line[], int lim)
{
  int c, i;

  for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

