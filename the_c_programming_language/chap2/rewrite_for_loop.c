#include <stdio.h>

main()
{
  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }

  int i = 0;
  while((c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }
    if (i < lim - 1) {
      break;
    }
    s[i] = c;
  }
}
