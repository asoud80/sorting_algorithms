#include "sort.h"

/**
*swap - Positions Of 2 Elements Into the Array.

*@array: an array
*@item1: the Array Element.

*@item2: the Array Element
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 *hoare_partition - to Hoare the Partition Sorting Scheme to be Implemented.

 *@array: an array.

 *@first: 1st Array Element.

 *@last: the Last Array Element.

 *@size: the Size Array.

 *Return: to Return a Position Of Last Element Sorted.
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 *qs - this a Qucksort Algorithm to be Implementated.

 *@array: an array.

 *@first: 1st Array Element.

 *@last: the Last Array Element.

 *@size: the Array Size
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 *quick_sort_hoare - to Prepare a Terrain To Quicksort Algorithm.

 *@array: an array

 *@size: the Array Size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
