#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, temp;
	bool swaped;

	if (!array || size < 2 || array == NULL)
		return;

	do {
		swaped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swaped = true;
				print_array(array, size);
			}
		}
	} while (swaped);

}
