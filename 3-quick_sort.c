#include "sort.h"

/**
 * swap - Swaps two elements.
 * @a: first element.
 * @b: second element.
 */

void swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/**
 * lomuto - Orders a subset of an array using lemuto partition scheme.
 * @array: Array to be partitioned.
 * @lower: Lower index of the partition.
 * @upper: Upper index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int lomuto(int *array, int lower, int upper, size_t size)
{
	int *pivot, above, below;

	pivot = array + upper;
	for (above = below = lower; below < upper; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - Implements the quick_sort algorithm using recursion.
 * @array: array to be sorted.
 * @lower: Lower index of the partition.
 * @upper: Upper index of the partition.
 * @size: size of the partition.
 */
void sort(int *array, int lower, int upper, size_t size)
{
	if (lower < upper)
	{
		int p = lomuto(array, lower, upper, size);

		sort(array, lower, p - 1, size);
		sort(array, p + 1, upper, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quick sort.
 * @array: array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	sort(array, 0, size - 1, size);
}
