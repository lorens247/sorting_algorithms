#include "sort.h"

/**
 * get_max - get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_arr, *out_arr, max, num, j, l;
    size_t i, k, m, n;

    // Check if array is empty or only contains one element
    if (size < 2)
        return;

    // Find the maximum value in the array
    max = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    // Allocate memory for count array and output array
    count_arr = malloc(sizeof(size_t) * (max + 1));
    out_arr = malloc(sizeof(int) * size);

    // Initialize count array with zeros
    for (j = 0; j <= max; j++)
        count_arr[j] = 0;

    // Count the occurrences of each value in the array
    for (k = 0; k < size; k++)
    {
        num = array[k];
        count_arr[num] += 1;
    }

    // Compute the running sum of the count array
    for (l = 1; l <= max; l++)
        count_arr[l] += count_arr[l - 1];

    // Debugging print of count array
    print_array(count_arr, max + 1);

    // Place each element in its sorted position in the output array
    for (m = 0; m < size; m++)
    {
        out_arr[count_arr[array[m]] - 1] = array[m];
        count_arr[array[m]]--;
    }

    // Copy the sorted output array back to the input array
    for (n = 0; n < size; n++)
        array[n] = out_arr[n];

    // Free memory allocated for count array and output array
    free(count_arr);
    free(out_arr);
}
