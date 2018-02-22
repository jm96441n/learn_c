#include <stdio.h>

int main()
{
	int chars, count;

	count = 0;

	while( (chars = getchar()) != EOF )
		if( chars == '\n' || chars == ' ' || chars == '\t' )
			++count;

	printf("%d\n", count);

}