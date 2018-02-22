// prints histogram of all characters entered into input
#include <stdio.h>

#define CHARS 128

int main()
{
	int ncharCount[CHARS];
	int i, c, j;

	for(i = 0; i < CHARS; i++){
		ncharCount[i] = 0;
	}

	while( (c = getchar()) != EOF){
		++ncharCount[c];
	}

	for(i = 0; i < CHARS; i++){
		printf("|%c| ", i);
		for(j = 1; j < ncharCount[i]; ++j){
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
