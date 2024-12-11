#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * partition - Partitions the array using Lomuto's scheme.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The total size of the array.
 *
 * Return: The index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;

for (int j = low; j < high; j++)
{
	if (array[j] <= pivot)
	{
		i++;
		swap(&array[i], &array[j]);
		if (i != j)
			print_array(array, size);
	}
}
swap(&array[i + 1], &array[high]);
if (i + 1 != high)
	print_array(array, size);

return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick sort.
 * @array: The array to sort.
 * @low: The starting index.
 * @high: The ending index.
 * @size: The total size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
	int pivot = partition(array, low, high, size);

	quick_sort_recursive(array, low, pivot - 1, size);
	quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
	return;

quick_sort_recursive(array, 0, size - 1, size);
}
