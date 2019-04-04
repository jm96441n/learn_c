#include <stdio.h>

/* replace tab, backspace, and back slash with \t, \b, \\ respectively */
main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {
      printf("yo");
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      putchar(c);
    }
  }
}
