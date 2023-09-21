#include "sort.h"
#include <stdio.h>


/**
 * bubble_sort - to Sort the Array Of Int In Ascending Order
 * @array: an Array Of Int
 *
 * @size: the size Of an Array
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	int tmp, sorted;
	size_t i;

	if (!array || size == 0)
		return;

	do {
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				sorted = 0;
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}

	} while (sorted == 0);
}
