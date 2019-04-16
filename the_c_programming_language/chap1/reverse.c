#include <stdio.h>
#define MAXLENGTH 1000

void reverse(char s[], int destSize);

main()
{
  char lineCopy[MAXLENGTH];
  int lineLength, c;

  lineLength = 0;
  while((c = getchar()) != EOF) {
    if (c == '\n') {
      reverse(lineCopy, lineLength);
      lineLength = 0;
    } else {
      lineCopy[lineLength] = c;
      ++lineLength;
    }
  }
}

void reverse(char original[], int destSize)
{
  int i;

  for (i = 0; i < destSize + 1; i++) {
    printf("%c", original[destSize - i]);
  }
  printf("\n");
}
