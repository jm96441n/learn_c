#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char h[]);

main() {
  char hex[10] = "0xa25";
  int converted = htoi(hex);
  printf("%d\n", converted);
}

/* convert hex string to integer */
int htoi(char h[])
{
  int i, startIndex, integerRepresentation;
  if (h[1] == 'x' || h[1] == 'X') {
    startIndex = 2;
  } else {
    startIndex = 0;
  }

  integerRepresentation = 0;
  int length = (int) (strlen(h));
  for (i = startIndex; i < length; i++) {
    if(isdigit(h[i])) {
      integerRepresentation += h[i] - '0';
    } else if (h[i] >= 'a' && h[i] <= 'f') {
      integerRepresentation += h[i] - 'a' + 10;
    } else if (h[i] >= 'A' && h[i] <= 'F') {
      integerRepresentation += h[i] - 'A' + 10;
    }
  }

  return integerRepresentation;
}


