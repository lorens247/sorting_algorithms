#include "sort.h"

/**
 * swap_ints - swap two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	a* = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: the array of integers
 * @size: size of the array
 *
 * Return: none
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		gap = gap / 3;
	}
}
