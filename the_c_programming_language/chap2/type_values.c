#include <stdio.h>

main()
{
  char high_char, low_char;
  short high_short, low_short;
  int high_int, low_int;
  long high_long, low_long;
  float high_float, low_float;
  double high_double, low_double;

  high_char = low_char = 1;
  high_short = low_short = 1;
  high_int = low_int = 1;
  high_long = low_long = 1;
  high_float = low_float = 1;
  high_double = low_double = 1;

  while(high_char > 0) {
    high_char++;
  }
  low_char = high_char - 1;
  printf("Char Range: %d - %d\n", low_char, high_char);
  
  while(high_short > 0) {
    high_short++;
  }
  low_short = high_short - 1;
  printf("Short Range: %hd - %hd\n", low_short, high_short);

  while(high_int > 0) {
    high_int++;
  }
  low_int = high_int - 1;
  printf("Int Range: %d - %d\n", low_int, high_int);

  while(high_long > 0) {
    high_long++;
  }
  low_long = high_long - 1;
  printf("Long Range: %ld - %ld\n", low_long, high_long);

  while(high_float > 0) {
    high_float++;
  }
  low_float = high_float - 1;
  printf("Float Range: %f - %f\n", low_float, high_float);

  while(high_double > 0) {
    high_double++;
  }
  low_double = high_double - 1;
  printf("Double Range: %f - %f\n", low_double, high_double);

}
