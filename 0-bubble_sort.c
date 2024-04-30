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
				print_bubble(array, size);
			}
		}
	} while (swaped);

}

/**
 * print_bubble - print print the array
 * @array: array to be printed
 * @size: the size of the array
 * Return: Nothing
 */
void print_bubble(const int *array, size_t size __attribute__((unused)))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			_printf(", ");
		_printf("%d", array[i]);
	}
	_printf("\n");
}
