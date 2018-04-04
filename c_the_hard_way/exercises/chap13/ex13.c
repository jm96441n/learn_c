#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;


	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	// states[4] = argv[1];
	// int argv_length = sizeof(argv) / sizeof(argv[0]);
	// argv[argv_length] = states[1];

	// go through each string in argv
	// why am I skipping argv[0]?
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}

	// int num_states = 4;
	int num_states = sizeof(states) / sizeof(states[0]);
	
	printf("num_states: %d\n", num_states);
	
	for (i = 0; i < num_states; i++) {
		printf("state %d: %s\n", i, states[i]);
	}

	return 0;
}
