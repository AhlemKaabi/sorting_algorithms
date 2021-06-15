#include "sort.h"
/**
 * Partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @size: size of the array
 * @high: highest index of the partition to sort
 *
 * Return: index of the pivot
*/
size_t Partition(int *array, int low, size_t size, int high)
{
	int pivot, aux;
	int keep_position, count;

	pivot = array[high];

	keep_position = low - 1;

	for (count = low;  count < high; count++)
	{
		if (array[count] < pivot)
		{
			keep_position++;
			if (keep_position != count)
			{
				aux = array[count];
				array[count] = array[keep_position];
				array[keep_position] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[keep_position + 1] > array[high])
	{
		aux = array[high];
		array[high] = array[keep_position + 1];
		array[keep_position + 1] = aux;
		print_array(array, size);
	}
	return (keep_position + 1);
}
/**
 * QuickSort - sorts a partition of an array of integers
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @size: size of the array
 * @high: highest index of the partition to sort
 *
 * Return: void
*/
void QuickSort(int *array, int low, size_t size, int high)
{
	size_t idx_pivot;

	if (low < high)
	{
		idx_pivot = Partition(array, low, size, high);
		QuickSort(array, low, size, idx_pivot - 1);
		QuickSort(array, idx_pivot + 1, size, high);
	}
}
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: array of integers.
 * @size: the size of the array.
*/
void quick_sort(int *array, size_t size)
{
	QuickSort(array, 0, size, size - 1);
}
