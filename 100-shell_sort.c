#include "sort.h"

/**
 *swap - helper funtion used to swap two values
 *@first: first value
 *#second: second value to swap
 */

void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
	gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				swap(&array[j - gap], &array[j]);
				j -= gap;
			}
		}

		gap = (gap - 1) / 3;
	}
}
