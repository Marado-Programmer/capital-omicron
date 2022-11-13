#include <stdlib.h>
#include <stdio.h>

void linear_search(int *arr, size_t len, int v);

void
linear_search(int *arr, size_t len, int v)
{
	// Ο(n) linear time
	// Time to complete grows in direct proportion to the amount of data
	for (size_t i = 0; i < len; ++i) {
		if (arr[i] == v) {
			printf("Value %d found in index %d!\n", v, (int) i);
		}
	}
}

int
main(int argc, char **argv)
{
	size_t len = argc > 1 ? atoi(argv[1]) : 1000;

	printf("LEN: %d\n", (int) len);

	int arr[len];

	srand(len);

	for (size_t i = 0; i < len; ++i)
		arr[i] = rand() % len;

	// Ο(1) constant time
	// It executes same amount of time regardless of the amount of data
	//printf("random number %d\n", arr[0]);
	//arr[69] = 420;

	linear_search(arr, len, 69);
}
