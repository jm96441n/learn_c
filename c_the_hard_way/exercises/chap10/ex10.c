#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("ERROR: You need one argument. \n");
		return 1;
	}

	int i = 0;

	for (i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
	    
		/* make letters lowercase using math 	
		if(letter > 64 && letter < 91) {
			letter += 32;
		}
		*/

		// make letters lowercase using tolower
		letter = tolower(letter);

		switch(letter) {
			case 'a':
				printf("%d: 'a' \n", i);
				break;
			case 'e':
				printf("%d: 'e' \n", i);
				break;
			case 'i':
				printf("%d: 'i' \n", i);
				break;
			case 'o':
				printf("%d: 'o' \n", i);
				break;
			case 'u':
				printf("%d: 'u' \n", i);
				break;
			case 'y':
				// why greater than 2?
				if(i > 2) {
					// because only sometimes y
					printf("%d: 'y' \n", i);	
				}
				break;	
			default:
				printf("%d: %c is not a vowel, try again \n", i, letter);
				break;
			
		}
	}
}
