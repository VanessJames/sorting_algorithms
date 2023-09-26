#include "sort.h"

/**
 * swap - helper function use to swap two elements
 * @first: first element
 * @second: secont element
 */

void swap(int *first, int *second)
{
	size_t temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array contains integer value
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
