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
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the 'Bubble sort' algorithm
 * @array: the array!
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int swap_elem = 1;
	size_t i;

	while (swap_elem)
	{
		swap_elem = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				swap_elem = 1;
			}
		}
	}
}
