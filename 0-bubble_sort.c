#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to an array of integers to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, count;
	int tmp;

	if (size < 2)
		return;

	while (size - 1 != count)
	{
		count = 0;
		i = 0;

		while (i + 1 != size)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
			else
				count++;
			i++;
		}
	}
}
