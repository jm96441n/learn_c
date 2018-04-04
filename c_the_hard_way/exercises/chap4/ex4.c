// this code will crash, used for working with lldb and valgrind debuggers
#include <stdio.h>

// cause the program to crash
void crash() {
    int *text = NULL;
    int i = 0;

    for(i = 0; i < 1000000; i++) {
        printf("%c", text[i]);
    }
}

int main(int argc, char *argv[])
{
	int age = 10;
	int height = 72;

	printf("I am %d years old \n", age);
	printf("I am %d inches tall \n", height);

    crash();
    crash();
    crash();
    crash();
    crash();

	return 0;
}
