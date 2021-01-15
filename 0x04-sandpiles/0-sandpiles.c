#include "sandpiles.h"
#include <stdio.h>

static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j];
		}
	}
}

int is_stable(int grid[3][3])
{
	int i, j, stable;
	stable = 1;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				stable = 0;
			}
		}
	}
	return (stable);
}

void topple(int grid[3][3])
{
	int future[3][3];
	int x, y;
	
	printf("=\n");
	print_grid(grid);
	
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] <= 3)
				future[x][y] = grid[x][y];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
			{
				future[x][y] += (grid[x][y] - 4);

				if (x > 0) /*up*/
					future[x - 1][y] += 1;

				if (y < 2) /*right*/
					future[x][y + 1] += 1;

				if (x < 2) /*down*/
					future[x + 1][y] += 1;

				if (y > 0) /*left*/
					future[x][y - 1] += 1;
			}
		}
	}
	copy_grid(grid, future);

}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int rows, columns;

	for (rows = 0; rows < 3; rows++)
	{
		for (columns = 0; columns < 3; columns++)
		{
			grid1[rows][columns] += grid2[rows][columns];
		}
	}
	topple(grid1);

	printf("=\n");
	print_grid(grid1);
}
