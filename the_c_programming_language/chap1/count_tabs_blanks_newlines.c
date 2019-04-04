#include <stdio.h>

/* count all tabs, spaces, and new lines in input */
main()
{
  int input, counter;

  counter = 0;

  while ((input = getchar()) != EOF) {
    if (input == '\t') {
      ++counter;
    }
    
    if (input == ' ') {
      ++counter;
    }

    if (input == '\n') {
      ++counter;
    }
  }

  printf("\n%d\n", counter);
}
