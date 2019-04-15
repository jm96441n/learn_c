#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_celsius(float fahr);
float cel_to_fahr(float cel);
void format_conversion_cel_to_fahr();
void format_conversion_fahr_to_cel();

main()
{
  format_conversion_fahr_to_cel();
  for(int i = 0; i < 3; i++) {
    printf("\n");
  }
  format_conversion_cel_to_fahr();
}

void format_conversion_cel_to_fahr()
{
  float fahr, cel;
  cel = LOWER;

  printf("Celsius \t Fahrenheit\n");

  while(cel <= UPPER) {
    fahr = cel_to_fahr(cel);
    printf("%3.0f\t\t%6.1f\n", cel, fahr);
    cel = cel + STEP;
  }

}

void format_conversion_fahr_to_cel()
{
  float fahr, cel;
  fahr = LOWER;

  printf("Fahrenheit \t Celsius\n");
  while(fahr <= UPPER) {
    cel = fahr_to_celsius(fahr);
    printf("%3.0f\t\t%6.1f\n", fahr, cel);
    fahr = fahr + STEP;
  }
}

/* Convert Fahrenheit to Celsius */
float fahr_to_celsius(float fahr)
{
  float cel = (5.0 / 9.0) * (fahr - 32.0);
  return cel;
}

/* Convert Celsius to Fahrenheit */
float cel_to_fahr(float cel) {
  float fahr = ((9.0 / 5.0) * cel) + 32.0;
  return fahr;
}
