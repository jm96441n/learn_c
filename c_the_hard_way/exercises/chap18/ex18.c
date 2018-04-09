#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Our old friend die from ex17
void die(const char *message)
{
	if(errno)
		perror(message);
	else
		printf("ERROR: %s\n", message);
	
	exit(1);
}

// a typedef causes a fake pointer, in this case 
// for a pointer function
typedef int (*compare_cb) (int a, int b);

// A classic bubble sort function that uses the compare_cb to 
// do the sorting
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int j = 0;
	int i = 0;
	int *target = malloc(count * sizeof(int));

	if(!target)
		die("Memory error.");
	
	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++) {
		for (j = 0; j < count - 1; j++) {
			if(cmp(target[j], target[j + 1]) > 0) {
				temp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

void merge(int *original_array, int *first_half, int *second_half, int left_count, int right_count, compare_cb cmp)
{
	int i, j, k;

	i = 0; j = 0; k = 0;
	while(i < left_count && j < right_count) {
		if(cmp(first_half[i], second_half[j]) > 0) {
			original_array[k++] = first_half[i++];
		} else {
			original_array[k++] = second_half[j++];
		}
	}

	while(i < left_count) {
		original_array[k++] = first_half[i++];
	}

	while(j < right_count) {
		original_array[k++] = second_half[j++];
	}

	return;
}

void merge_sort(int *numbers, int count, compare_cb cmp)
{
	int midpoint, i, *first_half, *second_half;
	if(count < 2) { 
		return;
	}
	
	midpoint = count / 2;

	first_half = (int*)malloc(midpoint * sizeof(int));
	second_half = (int*)malloc(midpoint * sizeof(int));

	for(i = 0; i < midpoint; i++) {
		first_half[i] = numbers[i];
	}

	for(i = midpoint; i < count; i++) {
		second_half[i - midpoint] = numbers[i];
	}
	
	merge_sort(first_half, midpoint, cmp);
	merge_sort(second_half, count - midpoint, cmp);
	merge(numbers, first_half, second_half, midpoint, count - midpoint, cmp);
	free(first_half);
	free(second_half);
	return;
}

int sorted_order(int a, int b)
{
	return (a > b) - (a < b);
}

int reverse_order(int a, int b)
{
	return (a < b) - (a > b);
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

// Used to test that we are sorting things correctly by doing the sort and printing it out
void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	//int *sorted = merge_sort(numbers, count, cmp);
	merge_sort(numbers, count, cmp);
	if(!numbers)
		die("Failed to sort as requested.");
	
	for (i = 0; i < count; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");

//	free(sorted);
	
	/* Break IT!!
	unsigned char *data = (unsigned char *)cmp;

	for(i = 0; i < 25; i++) {
		printf("%02x:", data[i]);
	}
	printf("%s", "\n");
	*/
}

int main(int argc, char *argv[])
{
	if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;

	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error.");
	
	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);
	
	free(numbers);

	return 0;
}
