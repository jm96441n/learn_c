#include <stdio.h>
#include <ctype.h>

void print_letters(char word[]);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("ERROR: You need at least one argument. \n");
		return 1;
	}
	int j = 0;
	for(j = 1; argv[j] != '\0'; j++) {
		printf("The vowels in '%s' are: \n", argv[j]);
		print_letters(argv[j]);
	}
	return 0;
}

void print_letters(char word[])
{
	int i = 0;
	for(i = 0; word[i] != '\0'; i++) {
		int letter = tolower(word[i]);
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
				if(i > 2){
					printf("%d: 'y' \n", i);
				}
				break;
			default:
				printf("%d '%c' is not a vowel! \n", i, letter);
				break;
		}
	}

	return;
}
