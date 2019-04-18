#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void escape(char s[], char t[]);

int main()
{
  char input[MAXLINE];
  char escaped[MAXLINE];
  printf("Enter your sentence to be escaped:\n");
  fgets(input, sizeof(input), stdin);
  printf("\n");
  escape(escaped, input);
  printf("Escaped sentence:\n");
  printf("%s", escaped);
  printf("\n");
  return 0;
}

void escape(char s[], char t[])
{
  int i, j;
  for(i = j = 0; i < strlen(t) - 1; ++i) {
    switch (t[i]) {
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  }
}
