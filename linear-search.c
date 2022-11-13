#include <stdlib.h>

int linear_search(int *arr, size_t len, int v);
int linear_search_sentinel(int *arr, size_t len, int v);
int linear_search_ordered(int *arr, size_t len, int v);

int
linear_search(int *arr, size_t len, int v)
{
	for (size_t i = 0; i < len; ++i) {
		if (arr[i] == v)
			return i;
	}

	return -1;
}

int
linear_search_sentinel(int *arr, size_t len, int v)
{
	// faster algorithm than linear_search by removing the i < len
	// comparasion
	arr[len] = v;

	for (size_t i = 0; 1; ++i) {
		if (arr[i] == v)
			return (int) i < v ? (int) i : -1;
	}
}

int
linear_search_ordered(int *arr, size_t len, int v)
{
	// If array is ordered we can stop once arr[i] is >= v

	for (size_t i = 0; i < len; ++i) {
		if (arr[i] >= v)
			return arr[i] == v ? (int) i : -1;
	}

	return -1;
}

int
main(int argc, char **argv)
{
	size_t len = argc > 1 ? atoi(argv[1]) : 1000;

	int arr[len];

	srand(len);

	for (size_t i = 0; i < len; ++i)
		arr[i] = rand() % len;

        /*
         * Linear Search / Sequential Search
         *
         * Search Algorithm
         *
         * Ο(n) --- linear time
	 * Ω(1) --- constant time
         *
         * Finds element within a list. It sequentialy check each element of
	 * the list until a match is found or the whole list has been searched.
         */

	linear_search(arr, len, 1);
	linear_search_sentinel(arr, len, 1);
	linear_search_ordered(arr, len, 1);
}
