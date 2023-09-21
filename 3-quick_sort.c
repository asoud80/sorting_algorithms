#include "sort.h"


/**
 * swap_items - to swap Two Items In the Array
 *
 * @array: an Array To Modify
 *
 * @l: an Index Of Left Item
 *
 * @r: an Index Of Right Item
 */

void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_range_lomuto - to Sort Sub Array Using
 *
 * Quick Sort Algorithm & lomuto's Partition Scheme
 *
 * @array: an Array Containing Sub-Array
 *
 * @low: to Start Position Of Sub-array
 *
 * @high: Ending Position Of Sub-array
 *
 * @size: Length Of an array
 */

void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t k, i;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	k = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				swap_items(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != high)
	{
		swap_items(array, k, high);
		print_array(array, size);
	}
	if (k - low > 1)
		quick_sort_range_lomuto(array, low, k - 1, size);
	if (high - k > 1)
		quick_sort_range_lomuto(array, k + 1, high, size);
}

/**
 * quick_sort - to Sort an Array Using Quick Sort Algorithm.
 *
 * and lomuto's partition Scheme
 *
 * @array: Array To Sort
 *
 * @size: Length Of an array.
 */

void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
