#include <stdio.h>
#define MAX_WORD_LEN 15
/* print out horiztonal histogram of word lengths in input */

main()
{
  int word_length, i, j, c;
  int counts[MAX_WORD_LEN];

  word_length = 0;

  for (i = 0; i < MAX_WORD_LEN; ++i) {
    counts[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (word_length >= MAX_WORD_LEN) {
        ++counts[MAX_WORD_LEN - 1];
      } else {
        ++counts[word_length - 1];
      }
      word_length = 0;
    } else {
      ++word_length;
    }
  }

  printf("\n");

  for (i = 0; i < MAX_WORD_LEN; ++i) {
    printf("%2d: ", i + 1);
    for (j = 0; j < counts[i]; ++j) {
      printf("| ");
    }
    printf("\n");
  }
}
