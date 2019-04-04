#include <stdio.h>

/* count lines in the input */
main()
{
  int c, nl;

  nl = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
  }

  printf("\n%d\n", nl);
}
