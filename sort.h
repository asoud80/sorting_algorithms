#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>


/**
 * struct listint_s - doubly_Linked_List Node.
 * @n: int Stored In The Node.
 *
 * @prev: a Pointer To Previous Element Of a List.
 *
 * @next: a Pointer To Next Element Of a List
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *next;
	struct listint_s *prev;
	}
listint_t;

/* functions to be printed */

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Sorting algorithms functions */
void quick_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

/*advanced tasks*/
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void heap_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif
