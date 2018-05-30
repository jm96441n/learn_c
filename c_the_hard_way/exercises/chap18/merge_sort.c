#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef int (*compare_cb) (int a, int b);

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

int normal_sort(int a, int b)
{
	return (a < b) - (a > b);
}

int reverse_sort(int a, int b)
{
	return (a > b) - (a < b);
}

void merge(int *original_array, int *first_half, int *second_half, int left_count, int right_count, compare_cb cmp)
{
	int i = 0; int j = 0; int k = 0;

	while(i < left_count && j < right_count){
		if(cmp(first_half[i], second_half[j]) > 0) {
			original_array[k++] = first_half[i++];
		} else {
			original_array[k++] = second_half[j++];
		}
	}

	while(i < left_count)
		original_array[k++] = first_half[i++];

	while(j < right_count)
		original_array[k++] = second_half[j++];

	return;
}

void merge_sort(int *numbers, int count, compare_cb cmp)
{
	if(count < 2)
		return;

	int midpoint, *first_half, *second_half;

	midpoint = count / 2;

	first_half = (int*)malloc(midpoint * sizeof(int));
	second_half = (int*)malloc(midpoint * sizeof(int));

	int i,j;

	for(i = 0; i < midpoint; i++) {
		first_half[i] = numbers[i];
	}

	i = 0;

	for(j = midpoint; j < count; j++) {
		second_half[i] = numbers[j];
		i++;
	}

	merge_sort(first_half, midpoint, cmp);
	merge_sort(second_half, count - midpoint, cmp);

	merge(numbers, first_half, second_half, midpoint, count - midpoint, cmp);

	free(first_half);
	free(second_half);
}

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	merge_sort(numbers, count, cmp);

	for(i = 0; i < count; i++) {
		printf("%d ", numbers[i]);
	}

	printf("%s", "\n");
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		die("USAGE: ./merge_sort 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;
	int *numbers = malloc(sizeof(int) * count);

	for(i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, normal_sort);
	test_sorting(numbers, count, reverse_sort);

	return 0;
}
