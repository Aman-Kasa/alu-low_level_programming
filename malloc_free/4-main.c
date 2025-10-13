#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - prints a grid of integers
 * @grid: 2D array
 * @width: width of grid
 * @height: height of grid
 */
void print_grid(int **grid, int width, int height)
{
	int h, w;

	for (h = 0; h < height; h++)
	{
		for (w = 0; w < width; w++)
			printf("%d ", grid[h][w]);
		printf("\n");
	}
}

/**
 * main - check free_grid function
 *
 * Return: Always 0
 */
int main(void)
{
	int **grid;

	grid = alloc_grid(6, 4);
	if (grid == NULL)
		return (1);

	print_grid(grid, 6, 4);
	printf("\n");
	grid[0][3] = 98;
	grid[3][4] = 402;
	print_grid(grid, 6, 4);
	free_grid(grid, 4);
	return (0);
}

