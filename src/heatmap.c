#include "dash.h"

int	**generate_heatmap(Field *field)
{
	int	**heatmap;
	int	i;
	int	j;

	heatmap = malloc(sizeof(int*) * (field->height + 1));
	i = 0;
	while (i < field->height)
	{
		heatmap[i] = malloc(sizeof(int) * (field->width + 1));
		j = 0;
		while (j < field->width)
		{
			heatmap[i][j] = abs(j - field->goal.x) + abs(i - field->goal.y);
			j++;
		}
		heatmap[i][j] = 0;
		i++;
	}
	heatmap[i] = 0;
	return (heatmap);
}

void	print_heatmap(int **heatmap, Field *field)
{
	int	i;
	int	j;

	printf("Heatmap:\n");
	i = 0;
	while (i < field->height)
	{
		j = 0;
		while (j < field->width)
		{
			printf("%d	", heatmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}