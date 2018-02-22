// converts temperature values using a function

#include <stdio.h>
#define LOWER  0
#define UPPER  300
#define STEP  20

int farenheit_to_celsius(int farenheit);
int celsisus_to_farenheit(int celsisus);

int main()
{
	char input, temp;
	int result;

	printf("temperature converter, type in C to convert to celsisus, and type in F to convert to farenheit\n");
	input = getchar();
	if(input == 'F' || input == 'f'){
		int cel;

		printf("\nFahrenheit   Celsisus\n");

		for(cel = LOWER; cel <= UPPER; cel = cel + STEP)
			printf("%3d\t\t%.6d\n", cel, celsisus_to_farenheit(cel));
	}else if( input == 'C' || input == 'c'){
		int fahr;

		printf("\nCelsius   Fahrenheit\n");

		for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
			printf("%3d\t\t%.6d\n", fahr, farenheit_to_celsius(fahr));

	}else{
		printf("Why are you like this?\n");
	}
}

int farenheit_to_celsius(int farenheit)
{
	double celsisus;

	celsisus = 5 * (farenheit/9) + 32;

	return celsisus;
}

int celsisus_to_farenheit(int celsisus)
{
	double farenheit;

	farenheit = 9 * (celsisus/5) - 32;

	return farenheit;
}