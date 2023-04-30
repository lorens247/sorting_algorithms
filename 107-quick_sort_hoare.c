#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    // Base case: if the size of the array is less than 2, it is already sorted
	if (size < 2)
		return;

    // Call the recursive helper function to perform the Quick Sort algorithm
	quick_recursion(array, 0, size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
    // Choose a pivot element and partition the array around it
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);

        // Recursively sort the left and right partitions
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv + 1, right, size);
	}
}

/**
 * partition - gives a piv index for Quicksort
 * @array: array to find the piv in
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: the index of the piv element
 */
int partition(int *array, int left, int right, size_t size)
{
    // Choose the rightmost element as the pivot
	int pivot = array[right], tmp, i = left - 1, j;

    // Iterate over the array from left to right
	for (j = left; j <= right; j++)
	{
        // If an element is less than the pivot, swap it with the element to the right of the current partition
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;

                // Print the current state of the array after the swap
				print_array(array, size);
			}
		}
	}

    // Swap the pivot with the element to the right of the current partition
	if (array[right] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;

        // Print the current state of the array after the swap
		print_array(array, size);
	}

    // Return the index of the pivot element
	return (i + 1);
}
