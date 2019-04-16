#include <stdio.h>
#define COLUMNLENGTH 80
#define MAXLINE 8000

void splitLineWithoutSpaces(char o[], int len, int lim);
void copy(char o[], char d[]);

main()
{
  int currentIndex, lastWhiteSpaceIndex, inLineIndex, c, i;
  char line[MAXLINE];

  currentIndex = 0;
  lastWhiteSpaceIndex = 0;
  inLineIndex = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      lastWhiteSpaceIndex = currentIndex;
    }

    if (inLineIndex >= COLUMNLENGTH) {
      line[lastWhiteSpaceIndex] = '\n';
      inLineIndex = 0;
    }

    line[currentIndex] = c;
    ++currentIndex;
    ++inLineIndex;
  }
  line[++currentIndex] = '\0';

  /* if line has no spaces */
  if (currentIndex > COLUMNLENGTH && lastWhiteSpaceIndex == 0) {
    splitLineWithoutSpaces(line, currentIndex, COLUMNLENGTH);
  }

  for (i = 0; i < currentIndex; ++i) {
    printf("%c", line[i]);
  }
  printf("\n");
}

void splitLineWithoutSpaces(char original[], int originalLength, int limit)
{
  char splitLine[MAXLINE];
  int i, j;
  j = 0;
  for (i = 0; i < originalLength; ++i) {
    if (i % limit == 0 && i != 0) {
      splitLine[j++] = '-';
      splitLine[j++] = '\n';
    }
    splitLine[j] = original[i];
    ++j;
  }
  splitLine[j] = '\0';
  copy(splitLine, original);
}

void copy(char origin[], char destination[])
{
  int c, i;
  i = 0;
  while((c = origin[i]) != '\0') {
    destination[i] = origin[i];
    ++i;
  }
}
