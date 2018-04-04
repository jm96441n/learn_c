#include <stdio.h>
#include <ctype.h>

// forward declaration
void print_statemet(int age, char name[], int version);

void print_statement(int age, char *name, int version)
{
	switch(version) {
		case 1:
			printf("%s has %d years alive. \n", name, age);
			break;
		case 2:
			printf("%s is %d years old. \n", name, age);
			break;
		case 3:
			printf("%s is %d years old again. \n", name, age);
			break;
		case 4:
			printf("%s lived %d years so far. \n", name, age);
			break;
		default:
			printf("That's not an option, try again");
			break;
	}
}

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// setup pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;
	
	// safely get the size of ages
	int count = sizeof(ages) / sizeof(ages[0]);
	int i = 0;

	// first way using indexing
	for (i = 0; i < count; i++) {
		// printf("%s has %d years alive. \n", cur_name[i], cur_age[i]);
		print_statement(ages[i], names[i], 1);
	}

	printf("----\n");

	// second way using pointers
	for (i = 0; i < count; i++) {
		// printf("%s is %d years old. \n", *(cur_name + i), *(cur_age + i));
		print_statement(*(cur_age + i), *(cur_name + i), 2);
	}

	printf("----\n");

	// third way, pointers are just arrays
	for (i = 0; i < count; i++) {
		// printf("%s is %d years old again. \n", cur_name[i], cur_age[i]);
		print_statement(cur_age[i], cur_name[i], 3);
	}	

	printf("----\n");

	// fourth way with pointers in a stupid complex way
	for (cur_name = names, cur_age = ages;
			(cur_age - ages) < count; cur_name++, cur_age++) {
		// printf("%s lived %d years so far. \n", *cur_name, *cur_age);
		print_statement(*cur_age, *cur_name, 4);
	}

	return 0;
}

