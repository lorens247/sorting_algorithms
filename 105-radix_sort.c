#include "sort.h"

/**
 * radix_sort -  sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	/* Initialize variables */
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	/* Find the maximum value in the array */
	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	/* Iterate through each digit in each number */
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		/* Sort the array by the current digit */
		count_sort_LSD(array, size, lsd);
		/* Print the current state of the array */
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	/* Initialize variables */
	int count_arr[10] = {0}, *out_arr, l, m;
	size_t k, n;

	/* Allocate memory for the output array */
	out_arr = malloc(sizeof(int) * size);

	/* Count the occurrences of each digit in the current LSD position */
	for (k = 0; k < size; k++)
		count_arr[(array[k] / lsd) % 10]++;

	/* Update the count array to reflect the positions of each digit in the output array */
	for (l = 1; l < 10; l++)
		count_arr[l] += count_arr[l - 1];

	/* Build the output array by placing each number in its correct position */
	for (m = size - 1; m >= 0; m--)
	{
		out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
	}

	/* Copy the output array back into the input array */
	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	/* Free the memory used by the output array */
	free(out_arr);
}
