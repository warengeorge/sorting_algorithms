#include "sort.h"
/**
 * swap - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @i: left element
 * @j: right element
 * @size: size of array
 */
void swap(int *array, int i, int j, int size)
{
	int aux;

	if (array[i] == array[j])
		return;
	aux = array[i];
	array[i] = array[j];
	array[j] = aux;
	print_array(array, size);
}
/**
 * partition - sort array partition
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 * Return: pivot sorted
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int split_idx = start;
	int j;

	for (j = start; j < end; j++)
		if (array[j] < pivot)
			swap(array, split_idx++, j, size);
	swap(array, split_idx, end, size);
	return (split_idx);
}
/**
 * recursive - quick_sort core
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = partition(array, start, end, size);

		recursive(array, start, pivot_pos - 1, size);
		recursive(array, pivot_pos + 1, end, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive(array, 0, size - 1, size);
}
