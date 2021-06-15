
#include "sort.h"

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
 *
 *
 *
 *
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
 *
 *
 *
 *
 */
void quick_sort(int *array, size_t size)
{
    QuickSort(array, 0, size, size - 1);
}