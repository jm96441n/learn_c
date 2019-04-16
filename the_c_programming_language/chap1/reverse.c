#include <stdio.h>
#define MAXLENGTH 1000

void reverse(char s[], char d[], int destSize);

main()
{
  char lineCopy[MAXLENGTH];
  int lineLength, c;

  lineLength = 0;
  while((c = getchar()) != EOF) {
    lineCopy[lineLength] = c;
    ++lineLength;
  }
  char reversedLine[lineLength];
  int i;

  reverse(lineCopy, reversedLine, lineLength);

  for(i = 0; i < lineLength + 1; ++i) {
    printf("%c", reversedLine[i]);
  }
  printf("\n");
}

void reverse(char original[], char reversed[], int destSize)
{
  int i;
  for (i = 0; i < destSize + 1; i++) {
    reversed[i] = original[destSize - i];
  }
}
