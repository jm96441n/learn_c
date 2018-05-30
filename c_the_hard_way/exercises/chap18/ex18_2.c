#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

typedef int (*compare_cb) (int a, int b);
typedef void (*sort_function) (int *array, int count, compare_cb cmp);

void merge(int *first_half, int *second_half, int *numbers, int first_count, int second_count, compare_cb cmp)
{
	int i = 0; int j = 0; int k = 0;

	while(i < first_count && j < second_count) {
		if(cmp(first_half[i], second_half[j]) < 0) {
			numbers[k++] = first_half[i++];
		} else {
			numbers[k++] = second_half[j++];
		}
	}

	while(i < first_count) {
		numbers[k++] = first_half[i++];
	}

	while(j < second_count) {
		numbers[k++] = second_half[j++];
	}

	return;
}

void merge_sort(int *numbers, int count, compare_cb cmp)
{
	int midpoint, i;
	if(count < 2)
		return;

	midpoint = count / 2;

	int *first_half = (int*)(malloc(sizeof(int) * midpoint));
	int *second_half = (int*)(malloc(sizeof(int) * midpoint));

	for(i = 0; i < midpoint; i++) {
		first_half[i] = numbers[i];
	}

	for(i = midpoint; i < count; i++) {
		second_half[i - midpoint] = numbers[i];
	}

	merge_sort(first_half, midpoint, cmp);
	merge_sort(second_half, count - midpoint, cmp);

	merge(first_half, second_half, numbers, midpoint, count - midpoint, cmp);

	free(first_half);
	free(second_half);
	return;
}

void bubble_sort(int *numbers, int count, compare_cb cmp)
{
  int temp = 0;
  int i = 0;
  int j = 0;

  for (i = 0; i < count; i++) {
    for (j = 0; j < count - 1; j++) {
      if (cmp(numbers[j], numbers[j + 1]) > 0) {
        temp = numbers[j + 1];
        numbers[j + 1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}

int sorted_order(int a, int b)
{
  return (a > b) - (a < b);
}

int reverse_order(int a, int b)
{
	return(a < b) - (a > b);
}

int strange_order(int a, int b)
{
	if(a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

void test_sorting(int *numbers, int count, compare_cb cmp, sort_function sf)
{
	int i = 0;
	int *sorted = malloc(sizeof(int) * count);

	memcpy(sorted, numbers, count * sizeof(int));

	sf(sorted, count, cmp);

	if (!sorted)
		die("Failed to sort as requested");

	for (i = 0; i < count; i++) {
		printf("%d ", sorted[i]);
	}

	printf("\n");

	free(sorted);
}

int main(int argc, char *argv[])
{
	if (argc < 2) die("USAGE: ex18_2 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error.");

	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	printf("Bubble sort: \n");
	test_sorting(numbers, count, sorted_order, bubble_sort);
	test_sorting(numbers, count, reverse_order, bubble_sort);
	test_sorting(numbers, count, strange_order, bubble_sort);

	printf("Merge sort: \n");
	test_sorting(numbers, count, sorted_order, merge_sort);
	test_sorting(numbers, count, reverse_order, merge_sort);
	test_sorting(numbers, count, strange_order, merge_sort);
	free(numbers);

	return 0;
}
