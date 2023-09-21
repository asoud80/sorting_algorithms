#include "sort.h"
#include <stdio.h>

/**
 * _swap - to Swap two Values
 *
 * @array: an Array For Swap the Values
 *
 * @i: 1st Index.
 *
 * @j: 2nd Index.
 *
 * Return: none
 */

void _swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}


/**
 * shell_sort - to Sort a list & Print Changes.
 *
 * @array: an Array To Sort
 *
 * @size: Size Of an array.
 *
 * Return: none
 */

void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				_swap(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
