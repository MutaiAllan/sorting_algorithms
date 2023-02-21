#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 * @a: First integer.
 * @b: Second integer.
 */

void swap_ints(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/**
 * bubble_sort - Sorts an array of integres.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Returns: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
