#include <stdio.h>

/* copy input to output, first version */
main()
{
  /* needs to be int and not char so that the variable c can hold the EOF constant which might
   * be larger than a char */
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
}

