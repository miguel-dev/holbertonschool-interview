#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_empty - Evaluates if a given pair of coordinates is empty.
 *
 * @y: Coordinate for y axis.
 * @x: Coordinate for x axis.
 * @size: Size of Sierpinski Carpet.
 *
 * Return: 1 if empty, 0 otherwise.
 */
int is_empty(int y, int x, int size)
{
	int d;

	for (d = 1; d < size; d *= 3)
	{
		if (((y % (3 * d)) / d == 1) && (((x % (3 * d)) / d == 1)))
			return (1);
	}
	return (0);
}

/**
 * menger - Prints a 2d dimensional menger sponge.
 *
 * @level: Level.
 */
void menger(int level)
{
	int x, y, size;

	if (level < 0)
	{
		return;
	}
	else if (level == 0)
	{
		printf("#\n");
	}
	else
	{
		size = pow(3, level);

		for (y = 0; y < size; y++)
		{
			for (x = 0; x < size; x++)
			{
				if (is_empty(y, x, size))
				{
					printf(" ");
				}
				else
				{
					printf("#");
				}
			}
			printf("\n");
		}
	}
}
