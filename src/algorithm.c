#include "dash.h"
#include <complex.h>
#include <stdio.h>

char	*generate_moveset(Field *field, int **heatmap, int *cost, int **walkmap)
{
	Vector2	curr_pos;
	char	next_move;
	unsigned int moves = 0;
	char	*moveset;

	moveset = malloc(sizeof(char) * 2);
	curr_pos = field->start;
	while (field->field[curr_pos.y][curr_pos.x] != GOAL)
	{
		next_move = get_cheapest_closest_direction(*field, curr_pos, heatmap, walkmap);
		if (next_move == -1)
		{
			free(moveset);
			return (NULL);
		}
		curr_pos = (Vector2){curr_pos.x + (next_move == RIGHT) - (next_move == LEFT),
			curr_pos.y + (next_move == DOWN) - (next_move == UP)};
		*cost = *cost + field->field[curr_pos.y][curr_pos.x];
		if (*cost < 0)
		{
			free(moveset);
			return (NULL);
		}
		moveset = realloc(moveset, sizeof(char) * (moves + 2));
		moveset[moves] = next_move;
		moveset[moves + 1] = 0;
		moves++;
		if (field->field[curr_pos.y][curr_pos.x] == GOAL)
			break ;
		field->field[curr_pos.y][curr_pos.x] = WALKED;
	}
	if (DEBUG)
		printf("Goal found after %d moves with cost %d\n", moves, *cost);
	if (field->field[curr_pos.y][curr_pos.x] == GOAL)
		return (moveset);
	free(moveset);
	return (NULL);
}

void	get_best_move(Field *field, int **heatmap, int **walkmap)
{
	char	*last_set;
	int		last_cost = __INT_MAX__;
	int		best_cost = __INT_MAX__;
	int		i = 0, j = 0, u = 0;
	Field	temp_field;

	temp_field.goal = field->goal;
	temp_field.start = field->start;
	temp_field.width = field->width;
	temp_field.height = field->height;
	temp_field.field = malloc(sizeof(char *) * (field->height + 1));
	temp_field.field[field->height] = 0;
	while (i < ITERATION_LIMIT)
	{
		u = 0;
		while (u < field->height)
		{
			temp_field.field[u] = strdup(field->field[u]);
			u++;
		}
		last_cost = 0;
		last_set = generate_moveset(&temp_field, heatmap, &last_cost, walkmap);
		if (DEBUG)
		{
			print_field(temp_field);
			print_walkmap(walkmap, &temp_field);
		}
		if (last_set != 0 && best_cost > last_cost)
		{
			best_cost = last_cost;
			write(1, last_set, strlen(last_set));
			write(1, "\n", 1);
			// printf("Best cost: %d\n", best_cost);
		}
		i++;

		j = 0;
		while (j < field->height)
		{
			free(temp_field.field[j]);
			j++;
		}
		free(last_set);
		last_set = 0;
	}
	free(temp_field.field);
}
