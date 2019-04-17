#include <stdio.h>
#define MAXLINE 1000

int any(char s1[], char s2[]);

int main()
{
  int location;
  char line1[MAXLINE];
  char line2[MAXLINE];
  printf("Enter your first string: ");
  fgets(line1, sizeof(line1), stdin);
  printf("\n");
  printf("Enter your second string: ");
  fgets(line2, sizeof(line2), stdin);
  printf("\n");
  location = any(line1, line2);

  if (location == -1) {
    printf("There are no characters in the second string present in the first");
  } else {
    printf("The first location of any character from the second string in the first is: %d", location);
  }

  printf("\n");

  return 0;
}

// returns the index of the first location in s1 that any character from s2 occurs
int any(char s1[], char s2[])
{
  int i, j, location;
  location = -1;

  for (i = 0; s1[i] != '\n'; ++i) {
    for (j = 0; s2[j] != '\n'; ++j) {
      if(s1[i] == s2[j] && location == -1) {
        location = i;
      }
    }
  }

  return location;
}
