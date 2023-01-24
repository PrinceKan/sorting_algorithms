#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in acending order using
 * the selection sort algorithm.
 * @array: An array of integers to needs to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	int low;
	size_t i, j, spot;

	if (array == NULL)
		return;
	i = 0;
	while (size > i)
	{
		low = array[i];
		spot = i;
		j = i + 1;

		while (size > j)
		{
			if (low > array[j])
			{
				spot = j;
				low = array[j];
			}
			j++;
		}
		if (spot != i)
		{
			array[spot] = array[i];
			array[i] = low;
			print_array(array, size);
		}
		i++;
	}
}
