#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 25;
	while(i > 0) {
		printf("The number is currently: %d \n", i);
		i--;
	}
	
	// need this to return a final newline
	printf("\n");

	return 0;
}
