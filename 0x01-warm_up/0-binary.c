#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - A binary search function
 *
 * @array: A pointer to a sorted integer array
 * @size: An unisgned integer value denoting the size of the array
 * @value: An integer indicating the value to be searched for.
 *
 * Return: The index of the located value or -1 if not found.
 */
int binary_search(int *array, size_t size, int value)
{
	int start = 0;
	int mid;
	int end = size - 1;
	int i;

	if (!array)
		return (-1);

	while (start <= end)
	{
		printf("Searching in array: ");
		for (i = start; i < end; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		mid = (end + start) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}
