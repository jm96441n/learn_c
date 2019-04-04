#include <stdio.h>

main()
{
  int fahr, cel;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  while(fahr <= upper) {
    cel = (5 * (fahr - 32)) / 9;
    printf("3%d 6%d\n", fahr, cel);
    fahr = fahr + step;
  }
}
