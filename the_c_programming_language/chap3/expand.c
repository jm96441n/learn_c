#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

void expander(char s1[], char s2[]);

int main()
{
  char shortened[MAXLINE];
  char expand[MAXLINE];
  printf("Enter your abbreviation to expand:\n");
  fgets(shortened, sizeof(shortened), stdin);
  expander(shortened, expand);
  printf("Expanded: \n%s\n", expand);
  return 0;
}

void expander(char shorty[], char expanded[])
{
  int i, j, start, end;
  start = 0;
  end = 0;

  i = 0;
  if (isalpha(shorty[i])) {
    start = shorty[i++];
  } else if (isdigit(shorty[i])) {
    while (isdigit(shorty[i])) {
      start = 10 * start + (shorty[i++] - '0');
    }
  }

  for (;i < strlen(shorty); ++i) {
    if (isalpha(shorty[i])) {
      end = shorty[i];
    } else {
      while (isdigit(shorty[i])) {
         end = 10 * end + (shorty[i++] - '0');
      }
    }
  }

  char result[3];
  for (i = 0, j = start; j <= end; ++j) {
    if(isalpha(j)) {
      expanded[i++] = j;
    } else {
      sprintf(result, "%d", j);
      for(int n = 0; n < strlen(result); ++n) {
        expanded[i++] = result[n];
      }
    }
  }
}
