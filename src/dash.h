#ifndef DASH_H
# define DASH_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define DEBUG 0
#define ITERATION_LIMIT 2147483647

#define UP_def 'U'
#define DOWN_def 'D'
#define LEFT_def 'L'
#define RIGHT_def 'R'
#define WALKED 'X'

# define START 'M'
# define GOAL 'G'

#define TRUE 1
#define FALSE 0

typedef struct Vector2
{
	int	x;
	int	y;
} 	Vector2;

typedef struct Field
{
	char	**field;
	int		width;
	int		height;
	Vector2	start;
	Vector2	goal;
} 	Field;

typedef enum Direction
{
	UP = UP_def,
	DOWN = DOWN_def,
	LEFT = LEFT_def,
	RIGHT = RIGHT_def
} 	Direction;

// parsing
Field	parse_file(char *filename);

// algorithm
void	get_best_move(Field *field, int **heatmap, int **walkmap);
// char	* generate_moveset(Field *field, int **heatmap, int *cost);

// utils
Vector2	get_goal(Field field);
Vector2	get_start(Field field);
void	print_field(Field field);
char	get_cheapest_closest_direction(Field field, Vector2 curr_pos, int **heatmap, int **walkmap);
int		is_valid_move(Field field, Vector2 curr_pos, Direction direction);
char	get_drection_to_goal(Field field, Vector2 curr_pos);

int		**generate_heatmap(Field *field);
void	print_heatmap(int **heatmap, Field *field);
int		**generate_walkmap(Field *field);
void	print_walkmap(int **walkmap, Field *field);

size_t	get_len(char *str);

#endif
