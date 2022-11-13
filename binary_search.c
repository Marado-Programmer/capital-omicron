#include <stdlib.h>
#include <math.h>

int binary_search(int *arr, size_t len, int v);
int binary_search_end_check(int *arr, size_t len, int v);
int binary_search_leftmost(int *arr, size_t len, int v);
int binary_search_rightmost(int *arr, size_t len, int v);

int
binary_search(int *arr, size_t len, int v)
{
	size_t start = 0, end = len - 1;
	while (start <= end) {
		int middle = floor((start + end) / 2);

		if (arr[middle] < v)
			start = middle + 1;
		else if (arr[middle] > v)
			end = middle - 1;
		else
			return middle;
	}

	return -1;
}

int
binary_search_end_check(int *arr, size_t len, int v)
{
	// removing one test for each iteration and testing only in the end.
	// When start and end are equal, we find the last possible position it
	// can be in. We test if it is there.

	size_t start = 0, end = len - 1;
	while (start != end) {
		int middle = (int) ceil((start + end) / 2);

		if (arr[middle] > v)
			end = middle - 1;
		else
			start = middle;
	}

	return arr[start] = v ? (int) start : -1;
}

int
binary_search_leftmost(int *arr, size_t len, int v)
{
	// Imagine the array [1,2,2,3,4]
	//
	// The normal binary search would give you the 2 index.
	// Imagine you want the index 1, the leftmost.

	size_t start = 0, end = len;
	while (start < end) {
		int middle = (int) floor((start + end) / 2);

		if (arr[middle] < v)
			start = middle + 1;
		else
			end = middle;
	}

	// maybe arr[start] != v but start is number of elements < v
	return (int) start;
}

int
binary_search_rightmost(int *arr, size_t len, int v)
{
	size_t start = 0, end = len;
	while (start < end) {
		int middle = (int) floor((start + end) / 2);

		if (arr[middle] > v)
			end = middle;
		else
			start = middle + 1;
	}

	// maybe arr[end - 1] != v but end - 1 is number of elements > v
	return (int) end - 1;
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
         * Binary Search / Half-Interval Search / Logarithmic Search /
	 * Binary Chop
         *
         * Search Algorithm
         *
         * Ο(log n) --- logarithmic time
	 * Ω(1) --- constant time
         *
	 * The array needs to be sorted.
	 *
	 * We compare a value in the middle of the array. If it's not equal our
	 * array not it's the half that can contain the value.
	 * Repeat until value found, or not found if the array now has 0 lenght
         */

	binary_search(arr, len, 1);
}
