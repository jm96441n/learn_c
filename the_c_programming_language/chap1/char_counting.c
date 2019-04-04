#include <stdio.h>

/* first way to count chars 
main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }

  printf("\n%ld\n", nc);
}
*/

/* second way to count chars */
main()
{
  double nc;
  for(nc = 0; getchar() != EOF; ++nc) {}
  printf("\n%.0f\n", nc);
}
