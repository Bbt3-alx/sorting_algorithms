#include "sort.h"

/**
 * swap - swap to element in an array
 * @a: first element
 * @b: second element
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - This function taks last element as pivot
 * @array: An Array
 * @low: Smallers element size in the array
 * @high: Greater element in the array
 * @size: the size of the @array.
 * Return: An integer
 */
int partition(int *array, int low, int high, size_t size)
{
	int low_idx, j, pivot;

	pivot = array[high];
	low_idx = (low - 1); /* Index of the smaller element */

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			low_idx++; /* Increment index of smaller element */
			swap(&array[low_idx], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[low_idx + 1], &array[high]);
	return (low + 1);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @size: the size of the array.
 * Return: Nothing
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
	else
		return;
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the @array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
