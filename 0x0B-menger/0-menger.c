#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_empty - Evaluates if a given pair of coordinates is empty.
 *
 * @y: Coordinate for y axis.
 * @x: Coordinate for x axis.
 *
 * Return: 1 if empty, 0 otherwise.
 */
int is_empty(int y, int x)
{
	if ((y % 3 == 1 || y / 3 == 1) && (x % 3 == 1 || x / 3 == 1))
		return (1);
	else
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
	else
	{
		size = pow(3, level);

		for (y = 0; y < size; y++)
		{
			for (x = 0; x < size; x++)
			{
				if (is_empty(y, x))
				{
					printf(" ");
				}
				else
					printf("#");
			}
			printf("\n");
		}
	}
}
