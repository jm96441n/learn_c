#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[], int arg_length);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++) {
		int arg_length = strlen(argv[i]);
		print_letters(argv[i], arg_length);
	}
}

void print_letters(char arg[], int arg_length)
{
	int i = 0;

	for (i = 0; i < arg_length; i++) {
		char ch = arg[i];

		if (can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

int can_print_it(char ch)
{
	return isalpha((int)ch) || isblank((int)ch);
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
