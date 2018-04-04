#include <stdio.h>

int main(int argc, char *argv[])
{
	char full_name[] = { 
		'Z', 'e', 'd',
		' ', 'A', '.', ' ',
		'S', 'h', 'a', 'w', '\0'
	};
	int areas[] = { 10, 12, 13, 14, 20 };
	char name[] = "Zed";

	// Warning on some systems you may have to change the 
	// %ld in this code to a %u since it will use unsigned ints

	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);
	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
	printf("The size of full name (char[]): %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    // break it + extra credit! uncomment the below lines to break this program
	// printf("COOOOMBO BRRRRRREEEEAAAAAKER\n");
	// printf("The first area is %d, the 2nd %d.\n", areas[10], areas[11]);
    
	// areas[0] = 100;
	// printf("The first element of areas is %d\n", areas[0]);

	// full_name[19] = 'A';
	// printf("Name is now: %s\n", full_name);
	// printf("size of name: %ld\n", sizeof(full_name));
	
	
	return 0;
}
