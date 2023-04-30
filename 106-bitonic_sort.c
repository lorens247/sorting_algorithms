#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    // Check if the array exists and is at least of size 2
	if (!array || size < 2)
		return;

	// Call the recursive function for bitonic sort
	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - recursive function for bitonic sort
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending or descending
 * @size: size of the array
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	// If there are at least two elements to sort
	if (r - l >= 1)
	{
		// Divide the sequence into two sub-sequences
		step = (r + l) / 2;

		// Print the current sequence being merged and its direction
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);

		// Recursively sort the two sub-sequences
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);

		// Merge the two sub-sequences in the given direction
		bitonic_merge(array, l, r, direction);

		// Print the sorted sequence and its direction
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - sorts and merges a sequence in ascending or descending order
 * @array: array to sort
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: ascending or descending
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	// If there are at least two elements to sort
	if (r - l >= 1)
	{
		// Sort and merge the left and right sub-sequences recursively
		for (i = l; i < l + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				tmp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = tmp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}
}
