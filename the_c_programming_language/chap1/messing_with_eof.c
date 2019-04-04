#include <stdio.h>

main()
{
  int c;

  /* first we show that getchar() != EOF will always be 0 or 1 
   c = getchar() != EOF; */

  /* second we print the value of EOF */
  c = EOF;

  printf("%d\n", c);
}
