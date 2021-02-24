#include "slide_line.h"

/**
 * slide_num - Slides a number on an array on a given direction.
 * @line: Address of array.
 * @position: Index of number in array.
 * @size: Size of array.
 * @direction: Direction of slide.
 */
void slide_num(int *line, size_t position, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		while (position > 0 && line[position - 1] == 0)
		{
			line[position - 1] = line[position];
			line[position] = 0;
			position--;
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		while (position < size - 1 && line[position + 1] == 0)
		{
			line[position + 1] = line[position];
			line[position] = 0;
			position++;
		}
	}
}

/**
 * merge - Merges two equal numbers on an array in the direction given.
 * @line: Address of array.
 * @position: Index of reference number on array.
 * @size: Size of array.
 * @direction: Direction of merge.
 */
void merge(int *line, size_t position, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
	{
		line[position - 1] += line[position];
		line[position] = 0;
		for (i = position; i + 1 < size; i++)
		{
			line[i] = line[i + 1];
			line[i + 1] = 0;
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		line[position + 1] += line[position];
		line[position] = 0;
		for (i = position; i > 0; i--)
		{
			line[i] = line[i - 1];
			line[i - 1] = 0;
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers in a given direction.
 * @line: Address of an array.
 * @size: Size of array.
 * @direction: Direction of sliding and merging.
 *
 * Return: 1 if succesful and 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
	{

		for (i = 1; i < size; i++)
		{
			if (line[i] != 0 && line[i - 1] == 0)
				slide_num(line, i, size, direction);
		}

		for (i = 1; i < size; i++)
		{
			if (line[i] != 0 && line[i] == line[i - 1])
				merge(line, i, size, direction);
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i + 1] == 0)
				slide_num(line, i, size, direction);
		}
		if (line[i] != 0 && line[i + 1] == 0)
			slide_num(line, i, size, direction);

		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i] == line[i + 1])
				merge(line, i, size, direction);
		}
		if (line[i] != 0 && line[i] == line[i + 1])
			merge(line, i, size, direction);

	}
	return (1);
}
