#include <stdio.h>

main()
{
  float fahr, cel;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  /* Convert Fahrenheit to Celsius */
  fahr = lower;

  printf("Fahrenheit \t Celsius\n");
  while(fahr <= upper) {
    cel = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t\t%6.1f\n", fahr, cel);
    fahr = fahr + step;
  }

  for(int i = 0; i < 3; i++) {
    printf("\n");
  }


  /* Convert Celsius to Fahrenheit */
  cel = lower;

  printf("Celsius \t Fahrenheit\n");

  while(cel <= upper) {
    fahr = ((9.0 / 5.0) * cel) + 32.0;
    printf("%3.0f\t\t%6.1f\n", cel, fahr);
    cel = cel + step;
  }
}
