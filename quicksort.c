#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(int *x, int *y);
size_t partition_lomuto(int *arr, size_t lo, size_t hi);
void quicksort_lomuto(int *arr, size_t lo, size_t hi);
size_t partition_hoare(int *arr, size_t lo, size_t hi);
void quick_hoare(int *arr, size_t lo, size_t hi);
int calc_mid(size_t lo, size_t hi);
void median_of_3(int *arr, size_t lo, size_t mid, size_t hi);
void ninther(int *arr, size_t lo, size_t hi);
size_t partition_hoare_median_of_three(int *arr, size_t lo, size_t hi);
void quick_hoare_median_of_three(int *arr, size_t lo, size_t hi);
size_t partition_hoare_ninther(int *arr, size_t lo, size_t hi);
void quick_hoare_ninther(int *arr, size_t lo, size_t hi);

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

size_t
partition_lomuto(int *arr, size_t lo, size_t hi)
{
	int pivot = arr[hi];

	size_t i = lo;

	for (size_t j = lo; j <= hi - 1; j++) {
		if (arr[j] <= pivot) {
			swap(&arr[i++], &arr[j]);
		}
	}

	swap(&arr[i], &arr[hi]);

	return i;
}

void
quicksort_lomuto(int *arr, size_t lo, size_t hi)
{
	if (lo >= hi) return;

	size_t p = partition_lomuto(arr, lo, hi);

	quicksort_lomuto(arr, lo, p - 1);
	quicksort_lomuto(arr, p + 1, hi);
}

size_t
partition_hoare(int *arr, size_t lo, size_t hi)
{
	int pivot = arr[(int) floor((hi + lo) / 2)];

	lo--;
	hi++;

	while (1) {
		do ++lo; while (arr[lo] < pivot);
		do --hi; while (arr[hi] > pivot);

		if (lo >= hi) return hi;

		swap(&arr[lo], &arr[hi]);
	}
}

void
quicksort_hoare(int *arr, size_t lo, size_t hi)
{
	if (lo >= hi) return;

	size_t p = partition_hoare(arr, lo, hi);

	quicksort_hoare(arr, lo, p);
	quicksort_hoare(arr, p + 1, hi);
}

int calc_mid(size_t lo, size_t hi)
{
	//return (int) floor((lo + hi) / 2); 
	return (int) floor(lo + (hi - lo) / 2); 
}

void
median_of_3(int *arr, size_t lo, size_t mid, size_t hi)
{
	if (arr[mid] < arr[lo])
		swap(&arr[lo], &arr[mid]);
	if (arr[hi] < arr[lo])
		swap(&arr[lo], &arr[hi]);
	if (arr[mid] < arr[hi])
		swap(&arr[mid], &arr[hi]);
}

void
ninther(int *arr, size_t lo, size_t hi)
{
	int inc = (int) floor(lo + (hi - lo) / 3); 
	int lo2 = lo + inc + 1;
	int lo3 = lo2 + inc;

	median_of_3(arr, lo, calc_mid(lo, lo + inc), lo + inc);
	median_of_3(arr, lo2, calc_mid(lo2, lo2 + inc - 1), lo2 + inc - 1);
	median_of_3(arr, lo3, calc_mid(lo3, hi), hi);

	median_of_3(arr, lo + inc, lo2 + inc - 1, hi);
}

size_t
partition_hoare_median_of_three(int *arr, size_t lo, size_t hi)
{
	int mid = calc_mid(lo, hi);
	median_of_3(arr, lo, mid, hi);

	int pivot = arr[hi];

	lo--;
	hi++;

	while (1) {
		do ++lo; while (arr[lo] < pivot);
		do --hi; while (arr[hi] > pivot);

		if (lo >= hi) return hi;

		swap(&arr[lo], &arr[hi]);
	}
}

void
quicksort_hoare_ninther(int *arr, size_t lo, size_t hi)
{
	if (lo >= hi) return;

	size_t p = partition_hoare(arr, lo, hi);

	quicksort_hoare(arr, lo, p);
	quicksort_hoare(arr, p + 1, hi);
}

size_t
partition_hoare_ninther(int *arr, size_t lo, size_t hi)
{
	ninther(arr, lo, hi);

	int pivot = arr[hi];

	lo--;
	hi++;

	while (1) {
		do ++lo; while (arr[lo] < pivot);
		do --hi; while (arr[hi] > pivot);

		if (lo >= hi) return hi;

		swap(&arr[lo], &arr[hi]);
	}
}

void
quicksort_hoare_median_of_three(int *arr, size_t lo, size_t hi)
{
	if (lo >= hi) return;

	size_t p = partition_hoare(arr, lo, hi);

	quicksort_hoare(arr, lo, p);
	quicksort_hoare(arr, p + 1, hi);
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
         * Quicksort
         *
         * Sorting Algorithm
         *
         * Ο(n^2) --- quadratic time
         * Ω(n log n) --- linearithmic time / loglinear time / quasilinear time
         */

	/*
	 * Why n log n?
	 *
	 * log n! = log n + log (n-1) + ... + log (1) = n log n
	 */

	for (size_t i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");

	//quicksort_lomuto(arr, 0, len - 1);
	//quicksort_hoare(arr, 0, len - 1);
	quicksort_hoare_median_of_three(arr, 0, len - 1);

	for (size_t i = 0; i < len; i++) printf("%d ", arr[i]);
	printf("\n");

	int sorted = 1;
	for (size_t i = 2; i < len; i++) if (arr[i-1]<arr[i-2]) { sorted = 0; break; }

	printf("SORTED? %s\n", sorted ? "TRUE" : "FALSE");
}
