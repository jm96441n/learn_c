#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchFor[]);

char pattern[] = "ould";

/* find all lines matching patter */

int main()
{
  char line[MAXLINE];
  int found = 0;

  while (getLine(line, MAXLINE) > 0) {
    if (strrindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  }
  return found;
}

/* getLine: get line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;

  i = 0;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  if (c =='\n') {
    s[i++] = c;
  }

  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      ;
    }

    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}

int strrindex(char s[], char t[])
{
  int i, j, k;
  int found_idx;
  int k_idx;
  int source_length = strlen(s);
  int pattern_length = strlen(t);

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      found_idx = i;
      ;
    }
    if (k > 0 && t[k] == '\0') {
      k_idx = k;
    }
    if ((source_length - i) < pattern_length) {
      break;
    }
  }

  if (k_idx > 0 && t[k_idx] == '\0') {
    printf("%d\n", found_idx);
    return found_idx;
  }

  printf("nope\n");
  return -1;
}
