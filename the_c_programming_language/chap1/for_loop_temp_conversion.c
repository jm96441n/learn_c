#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20

main() {
  /* Fahr to Cel*/
  printf("Fahrenheit \t Celsius\n");
  for(int fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%3d \t\t %6.1f\n", fahr, ((5.0 / 9.0) * (fahr - 32)));
  }

  for(int i = 0; i < 4; i++) {
    printf("\n");
  }

  /* Cel to Fahr */
  printf("Celsius \t Fahrenheit\n");
  for(int cel = UPPER; cel >= LOWER; cel -= STEP) {
    printf("%3d \t\t %6.1f\n", cel, (((9.0 / 5.0) * cel) + 32));
  }
}
