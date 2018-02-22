#include <stdio.h>
#define LOWER  0
#define UPPER  300
#define STEP  20
/* prints out a conversion of farenheit to celsius in steps of 20 degrees F*/
int main()
{
	/*
	how you wrote it initially

	int cel, far;

	int step = 20;
	int lower = 0;
	int upper = 300;
	*/

// this is from the first part of the exercise
	// int cel, far;
	// int step, lower, upper;

	// step = 20;
	// lower = 0;
	// upper = 300;

	// printf("F\tC\n");

	// far = lower;

	// while (far <= upper){
	// 	cel = 5 * (far - 32) / 9;
	// 	printf("%d\t%d\n", far, cel);
	// 	far = far + step;
	// }

	// return 0;

// for loop with constants

	int fahr;

	for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d\t%.6f\n", fahr, (5.0/9.0) * (fahr - 32));

	return 0;
}