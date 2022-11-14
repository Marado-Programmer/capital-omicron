#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y);
void bubble_sort(int *arr, size_t len);
void bubble_sort_test(int *arr, size_t len);
void bubble_sort_ignore_last(int *arr, size_t len);
void bubble_sort_optimized(int *arr, size_t len);

void
swap(int *x, int *y)
{
	//*x ^= *y;
	//*y ^= *x;
	//*x ^= *y;
	int temp = *x;
	*x = *y;
	*y = temp;
}

void
bubble_sort(int *arr, size_t len)
{
	for (size_t i = 0; i < len - 1; ++i) {
		for (size_t j = 0; j < len - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void
bubble_sort_test(int *arr, size_t len)
{
	// If it didn't swap nothing then it's already in order

	int swaped;
	do {
		swaped = 0;
		for (size_t i = 0; i < len - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				swaped = 1;
			}
		}
	} while (!swaped);
}

void
bubble_sort_ignore_last(int *arr, size_t len)
{
	// The greatest number will always be on the last place of the array
	// after an iteration.
	// Because of this we can avoid looking at the last place by
	// decrementing the array lenght number.

	int swaped;
	do {
		swaped = 0;
		for (size_t i = 0; i < len - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				swaped = 1;
			}
		}
		--len;
	} while (!swaped);
}

void
bubble_sort_optimized(int *arr, size_t len)
{
	// Maybe not only one element is placed in their final position.
	// We can check the last place swaped and making the len = that
	// position.
	// We can remove the swaped variable because the new lenght starts at 0
	// making if nothing swaps the next position to look at is 0 and -1 so
	// we do nothing.

	--len;
	do {
		int newlen = 0;
		for (size_t i = 1; i <= len; ++i) {
			if (arr[i - 1] > arr[i]) {
				swap(&arr[i], &arr[i - 1]);
				newlen = i;
			}
		}
		len = newlen;
	} while (len > 1);
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
         * Bubble Sort / Sinking Sort
         *
         * Sorting Algorithm --- Comparasion Sort
         *
         * Data Structure --- Array
         *
         * Ο(n^2) --- quadric time
         * Ω(n) --- linear time
         *
         * Repeatedly steps through the input array element by element,
         * comparing the current one with the one after and swaiping the values
         * if needed.
         */

        //bubble_sort(arr, len);
	//bubble_sort_test(arr, len);
	//bubble_sort_ignore_last(arr, len);
	
	for (size_t i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");

	bubble_sort_optimized(arr, len);

	for (size_t i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");

	int sorted = 1;
	for (size_t i = 2; i < len; i++) if (arr[i-1]<arr[i-2]) { sorted = 0; break; }

	printf("SORTED? %s\n", sorted ? "TRUE" : "FALSE");
}
