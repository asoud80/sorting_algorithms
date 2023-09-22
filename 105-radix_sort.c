#include <stdlib.h>
#include "sort.h"

/**
 * csort2 - Auxiliary Functions Of Radix Sort.
 * @array: the Array Of Data To Be Sorted.
 *
 * @buff: Malloc Buffer.
 *
 * @size: the Size Of Data.
 *
 * @lsd: less Significant Digit
 * Return: no return
 */

void csort2(int *array, int **buff, int size, int lsd)
{
	int i, j, csize = 10, num;
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[i];
		carr[num] += 1;
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (carr[i] > 0)
		{
			array[j] = buff[i][carr2[i]];
			carr2[i] += 1, carr[i] -= 1;
			j++;
		}
	}

	print_array(array, size);

}

/**
 * csort - Auxiliary Function Of Radix Sort
 * @array: the Array Of Data To Be Sorted.
 *
 * @size: the Size Of Data.
 *
 * @lsd: less Significant digit
 * Return: no return
 */

void csort(int *array, int size, int lsd)
{
	int i, j, num, csize = 10, **buff;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < csize; i++)
		if (carr[i] != 0)
			buff[i] = malloc(sizeof(int) * carr[i]);


	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (i = 0; i < csize; i++)
		if (carr[i] > 0)
			free(buff[i]);
	free(buff);
}

/**
 * radix_sort - to Sort the Array Of Int In Ascending Order Use a radix
 *
 * Sort Algorithm
 * @array: the Array Of the Data To Be Sorted.
 *
 * @size: the Size Of Data
 * Return: no return
 */

void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
