#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
  int i;
  int arr[5];
  for(i = 5; i < 10; i++) {
    arr[i - 5] = i;
  }

  printf("found %d at %d\n", 7, binsearch(7, arr, 4));
  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;

  while (low <= high && v[mid] != x) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;   
    } else {
      low = mid + 1;
    }
  }
  return v[mid] == x ? mid : -1;
}
