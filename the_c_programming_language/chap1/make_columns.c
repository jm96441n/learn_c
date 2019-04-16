#include <stdio.h>
#define COLUMNLENGTH 80
#define MAXLINE 8000

main()
{
  int currentIndex, lastWhiteSpaceIndex, inLineIndex, c, i;
  char line[MAXLINE];

  currentIndex = 0;
  lastWhiteSpaceIndex = 0;
  inLineIndex = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
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
  for(i = 0; i < currentIndex; ++i) {
    printf("%c", line[i]);
  }
}
