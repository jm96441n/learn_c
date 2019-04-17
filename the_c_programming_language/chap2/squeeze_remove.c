#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 1000

void squeeze_all(char s[], char d[]);
void squeeze(char s[], char c);

main()
{
  char line1[MAXLINE];
  char line2[MAXLINE];
  printf("Enter your first sentence: ");
  fgets(line1, sizeof(line1), stdin);
  printf("Enter your second sentence: ");
  fgets(line2, sizeof(line2), stdin);
  squeeze_all(line1, line2);
  printf("New first sentence: %s\n", line1);
}

void squeeze_all(char s1[], char s2[])
{
  int i;
  for (i = 0; s2[i] != '\0'; ++i) {
    squeeze(s1, s2[i]);
  }
}

void squeeze(char line[], char character)
{
  int i, j;
  for (i = j = 0; line[i] != '\0'; i++) {
    if (line[i] != character) {
      line[j++] = line[i];
    }
  }
  // new end of line is at j
  line[j] = '\0';
}
