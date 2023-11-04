#include "dash.h"
#include <stddef.h>

size_t	get_len(char *str)
{
	size_t	len = 0;

	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

Vector2	get_goal(Field field)
{
	for (int x = 0; x < field.width; x++)
	{
		for (int y = 0; y < field.height; y++)
		{
			if (field.field[y][x] == GOAL)
				return ((Vector2){x, y});
		}
	}
	return (Vector2){-1, -1};
}

Vector2	get_start(Field field)
{
	for (int x = 0; x < field.width; x++)
	{
		for (int y = 0; y < field.height; y++)
		{
			if (field.field[y][x] == START)
				return ((Vector2){x, y});
		}
	}
	return (Vector2){-1, -1};
}

void	print_field(Field field)
{
	printf("Field:\n");
	for (int y = 0; y < field.height; y++)
	{
		for (int x = 0; x < field.width; x++)
		{
			char	c = field.field[y][x];
			if (c >= 1 && c <= 9)
				c += '0';
			printf("%c", c);
		}
		printf("\n");
	}
}

int	is_valid_move(Field field, Vector2 curr_pos, Direction direction)
{
	switch (direction)
	{
		case UP:
			if (curr_pos.y - 1 < 0)
				return FALSE;
			if (field.field[curr_pos.y - 1][curr_pos.x] == WALKED)
				return FALSE;
			break;
		case DOWN:
			if (curr_pos.y + 1 >= field.height)
				return FALSE;
			if (field.field[curr_pos.y + 1][curr_pos.x] == WALKED)
				return FALSE;
			break;
		case LEFT:
			if (curr_pos.x - 1 < 0)
				return FALSE;
			if (field.field[curr_pos.y][curr_pos.x - 1] == WALKED)
				return FALSE;
			break;
		case RIGHT:
			if (curr_pos.x + 1 >= field.width)
				return FALSE;
			if (field.field[curr_pos.y][curr_pos.x + 1] == WALKED)
				return FALSE;
			break;
	}
	return TRUE;
}

char	get_cheapest_closest_direction(Field field, Vector2 curr_pos, int **heatmap, int **walkmap)
{
	int		cheapest = __INT_MAX__;
	int 	temp = 0;
	char	dir = -1;

	// check up
	if (is_valid_move(field, curr_pos, UP_def))
	{
		temp = field.field[curr_pos.y - 1][curr_pos.x];
		if (temp == GOAL)
			return (UP_def);
		temp += heatmap[curr_pos.y - 1][curr_pos.x];
		temp += walkmap[curr_pos.y - 1][curr_pos.x];
		if (temp < cheapest)
		{
			dir = UP_def;
			cheapest = temp;
		}
	}

	// check down
	if (is_valid_move(field, curr_pos, DOWN_def))
	{
		temp = field.field[curr_pos.y + 1][curr_pos.x];
		if (temp == GOAL)
			return (DOWN_def);
		temp += heatmap[curr_pos.y + 1][curr_pos.x];
		temp += walkmap[curr_pos.y + 1][curr_pos.x];
		if (temp < cheapest)
		{
			dir = DOWN_def;
			cheapest = temp;
		}
	}

	// check left
	if (is_valid_move(field, curr_pos, LEFT_def))
	{
		temp = field.field[curr_pos.y][curr_pos.x - 1];
		if (temp == GOAL)
			return (LEFT_def);
		temp += heatmap[curr_pos.y][curr_pos.x - 1];
		temp += walkmap[curr_pos.y][curr_pos.x - 1];
		if (temp < cheapest)
		{
			dir = LEFT_def;
			cheapest = temp;
		}
	}

	// check right
	if (is_valid_move(field, curr_pos, RIGHT_def))
	{
		temp = field.field[curr_pos.y][curr_pos.x + 1];
		if (temp == GOAL)
			return (RIGHT_def);
		temp += heatmap[curr_pos.y][curr_pos.x + 1];
		temp += walkmap[curr_pos.y][curr_pos.x + 1];
		if (temp < cheapest)
		{
			dir = RIGHT_def;
			cheapest = temp;
		}
	}

	switch (dir)
	{
		case UP_def:
			walkmap[curr_pos.y - 1][curr_pos.x] += 1;
			break;
		case DOWN_def:
			walkmap[curr_pos.y + 1][curr_pos.x] += 1;
			break;
		case LEFT_def:
			walkmap[curr_pos.y][curr_pos.x - 1] += 1;
			break;
		case RIGHT_def:
			walkmap[curr_pos.y][curr_pos.x + 1] += 1;
			break;
	}

	return (dir);
}
