#include "sort.h"
/**
* swap - function that swap elements.
* @a: pointer to 1st element
* @b: pointer to 2nd element
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx_of_min = 0;

	for (i = 0; i < size; i++)
	{
		idx_of_min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[idx_of_min])
			{
				idx_of_min = j;
			}
		}
		if (idx_of_min != i)
		{
			swap(&array[i], &array[idx_of_min]);
			print_array(array, size);

		}

	}
}
