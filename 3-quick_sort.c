#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in asceding order using the
 * quick sort algorithm implementing the Lomuto partition scheme.
 * @array: Array of integers that need to be sorted.
 * @size: The size of the array to sort.
 */
void quick_sort(int *array, size_t size)
{
	size_t onset;

	onset = 0;
	if (size < 2 || array == NULL)
		return;
	size = size - 1;
	sort(array, onset, size, size + 1);
}

/**
 * sort - Does the actual sorting.
 * @array: Array of integers that need to be sorted.
 * @onset: The lower bound of the array partition.
 * @finish: The upper bound of the array partion.
 * @og: The original size of the whole array. Used only for printing.
 */
void sort(int *array, size_t onset, size_t finish, size_t og)
{
	size_t i, j;
	int piv, index, c;

	piv = array[finish];
	j = onset;
	i = j - 1;
	index = 0;
	j = onset;

	while (finish > j)
	{
		if (array[j] <= piv)
		{
			i++;
			index = switcher(array, j, i, og);
		}
		j++;
	}
	i++;
	index = switcher(array, j, i, og);

	if (index == 0)
	{
		c = inspect(array, onset, finish);
		if (c == 1)
			sort(array, onset, finish - 1, og);
	}
	else
	{
		sort(array, onset, i, og);
		sort(array, i, finish, og);
	}
}

/**
 * switcher - Swaps the numbers in the array.
 * @array: Array of integers that need to be sorted.
 * @i: The lower bound of the array partition.
 * @j: The upper bound of the array partion.
 * @og: The original size of the whole array. Used only for printing.
 * Return: 1 when a swap happens. 0 otherwise.
 */
int switcher(int *array, size_t i, size_t j, size_t og)
{
	int tmp;

	if (j != i)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, og);
		return (1);
	}
	return (0);
}

/**
 * inspect - checks if the array portion is already sorted.
 * @array: Array of integers that need to be sorted.
 * @onset: The lower bound of the array partition.
 * @finish: The upper bound of the array partion.
 * Return: 1 if the array is not sorted. 0 otherwise.
 */
int inspect(int *array, size_t onset, size_t finish)
{
	size_t i;

	i = onset;

	while (finish > i)
	{
		if (array[i + 1] < array[i])
			return (1);
		i++;
	}
	return (0);
}
