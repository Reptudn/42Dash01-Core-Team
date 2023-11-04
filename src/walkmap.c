#include "dash.h"
#include <stdio.h>
#include <stdlib.h>

int		**generate_walkmap(Field *field)
{
	int		**walkmap;
	int		i;
	int		j;

	walkmap = malloc(sizeof(int *) * (field->height + 1));
	i = 0;
	while (i < field->height)
	{
		walkmap[i] = (int *)malloc(sizeof(int) * (field->width + 1));
		j = 0;
		while (j < field->width)
		{
			walkmap[i][j] = 0;
			j++;
		}
		walkmap[i][j] = 0;
		i++;
	}
	walkmap[i] = 0;
	// printf("Walkmap generated\n");
	return (walkmap);
}

void print_walkmap(int **walkmap, Field *field)
{
	int	x;
	int	y;

	y = 0;
	printf("Walkmap:\n");
	while (y < field->height)
	{
		x = 0;
		while (x < field->width)
		{
			printf("%d	", walkmap[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
