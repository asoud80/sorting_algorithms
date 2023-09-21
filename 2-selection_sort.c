#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - to Sort the Array Of Int In Ascending Order
 *
 * @array: an array
 *
 * @size: Size Of an Array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, step, min_idx;

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
				min_idx = i;
		}

		if (min_idx != step)
		{
			tmp = array[step];
			array[step] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
