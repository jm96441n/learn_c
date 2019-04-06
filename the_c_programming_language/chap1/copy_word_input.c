#include <stdio.h>

/* copy input character for character with each word on a new line 8 */

main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ' ||  c == '\n' || c == '\t') {
      printf("\n");
    } else {
      printf("%c", c);
    }
  }
}
