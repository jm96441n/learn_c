#include <stdio.h>

#define IN 0
#define OUT 1

int main()
{
	int nwordCount[10];

	for(int i = 0; i < 10; ++i){
		nwordCount[i] = 0;
	}

	int state;
	int wordlen = 0;
	char c;

	while( (c = getchar()) != EOF ){
		if( c == ' ' || c == '\n' || c == '\t'){
			++nwordCount[wordlen];
			wordlen = 0;
		}else {
			++wordlen;
		}
	}

	for(int i = 0; i < 10; ++i){
		int j = 0;
		printf("%d    :", i);
		while( j < nwordCount[i] ){
			putchar('|');
			++j;
		}
		putchar('\n');
	}
}