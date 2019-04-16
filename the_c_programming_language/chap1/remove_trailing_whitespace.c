#include <stdio.h>
#define TABLENGTH 2
#define MAXLINE 1000

main()
{
  char line[1000];
  int c, i, j;

  i = 0;
  while((c = getchar()) != EOF) {
    if (c == '\t') {
      for(j = 0; j < TABLENGTH; ++j) {
        line[i] = ' ';
        ++i;
      }
    } else {
      line[i] = c;
      ++i;
    }
  }
  printf("%s", line);
}
