#include <stdio.h>
#define TOTAL_CHAR_COUNT 96
#define OFFSET 32

/* print histogram of frequencies of characters in input */

main()
{
  int c, i, j;
  int char_counts[TOTAL_CHAR_COUNT];

  for (i = 0; i < TOTAL_CHAR_COUNT; ++i) {
    char_counts[i - OFFSET] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++char_counts[c - OFFSET]; 
  }

  printf("\n");

  for (i = 0; i < TOTAL_CHAR_COUNT; ++i) {
    printf("%c: ", i + OFFSET);
    for (j = 0; j < char_counts[i]; ++j) {
      printf("# ");
    }
    printf("\n");
  }
}
