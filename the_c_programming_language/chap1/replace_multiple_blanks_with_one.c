#include <stdio.h>

/* in an input string replace multiple blanks with a single blank */
main()
{
  int current_character, previous_character;

  while ((current_character = getchar()) != EOF) {
    if ((current_character != ' ') || (current_character != previous_character)) {
      previous_character = current_character;
      putchar(current_character);
    }
  }
}
