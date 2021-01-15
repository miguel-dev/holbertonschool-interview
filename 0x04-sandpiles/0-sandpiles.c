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
	return stable;
}

void topple(int grid[3][3])
{
	int future[3][3];
	int rows, columns;/*, stable;*/
	/*stable = 0;*/

	/*while (!stable)
	{*/
		for (rows = 0; rows < 3; rows++)
		{
			for (columns = 0; columns < 3; columns++)
			{
				if (grid[rows][columns] <= 3)
				{
					future[rows][columns] = grid[rows][columns];
				}
			}
		}
	
		for (rows = 0; rows < 3; rows++)
		{
			for (columns = 0; columns < 3; columns++)
			{
				if(grid[rows][columns] > 3)
				{
					future[rows][columns] += (grid[rows][columns] - 4);

					if (rows > 0) /*up*/
					{
						future[rows - 1][columns] += 1;
					}
					if (columns < 2) /*right*/
					{
						future[rows][columns + 1] += 1;
					}
					if (rows < 2) /*down*/
					{
						future[rows + 1][columns] += 1;
					}
					if (columns > 0) /*left*/
					{
						future[rows][columns - 1] += 1;
					}
				}
			}
		}
		copy_grid(grid, future);

		/*stable = is_stable(grid1);*/

		printf("=\n");
		print_grid(grid);
	/*}*/
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
}
