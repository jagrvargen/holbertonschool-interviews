#include "slide_line.h"
int left(int *line, size_t size);
int right(int *line, size_t size);

/**
 * slide_line - A simple reproduction of the 2048 game.
 *
 * @line: A pointer to an array of integers.
 * @size: An unsigned integer denoting the size of the array.
 * @direction: An int which denotes the direction to slide integer values.
 *
 * Return: An integer 1 upon success, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);

	if (direction == 2)
		return (left(line, size));

	if (direction == 3)
		return (right(line, size));

	return (0);
}

/**
 * left - shift integers left
 *
 * @line: Pointer to array
 * @size: Size of array
 *
 * Return: 1
 */
int left(int *line, size_t size)
{
	int i, j;

	i = 0;
	j = 1;
	while (i < j && j < (int) size)
	{
		if (line[i] == line[j] && line[i] > 0)
		{
			line[i++] *= 2;
			line[j] = 0;
		}
		else if (line[i] == 0 && line[j] > 0)
		{
			line[i] = line[j];
			line[j] = 0;
		}
		else if (line[i] > 0 && line[j] > 0)
			line[++i] = line[j];
		j++;
	}

	return (1);
}

/**
 * right - Shift the integers right
 *
 * @line: Pointer to integer array
 * @size: Size of array
 *
 * Return: 1
 */
int right(int *line, size_t size)
{
	int i, j;

	i = (int) size - 2;
	j = (int) size - 1;
	while (i >= 0 && j > i)
	{
		if (line[i] == line[j] && line[j] > 0)
		{
			line[j--] *= 2;
			line[i] = 0;
		}
		else if (line[j] == 0 && line[i] > 0)
		{
			line[j] = line[i];
			line[i] = 0;
		}
		else if (line[j] > 0 && line[i] > 0)
			line[--j] = line[i];
		i--;
	}

	return (1);
}
