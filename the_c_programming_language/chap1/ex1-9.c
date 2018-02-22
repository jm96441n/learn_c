#include <stdio.h>

int main()
{
	int c, prev_c;

	printf("Write some characters, when you're done press ctrl+D\n");
	while( (c = getchar()) != EOF )
		if( c == prev_c && c == ' '){
			prev_c = c;
		}
		else{
			prev_c = c;
			putchar(c);
		}

	return 0;
}
