#include "dash.h"

int	main(int argc, char* argv[])
{
	Field	field;
	int		**walkmap;
	int		**heatmap;

	if (argc != 2)
	{
		printf("Usage: ./marvin <filename>\n");
		return (0);
	}
	field = parse_file(argv[1]);
	walkmap = generate_walkmap(&field);
	heatmap = generate_heatmap(&field);
	if (DEBUG)
	{
		print_field(field);
		print_walkmap(walkmap, &field);
		printf("Width: %d\nHeight: %d\n", field.width, field.height);
		print_heatmap(heatmap, &field);
		printf("Start: %d, %d\n", field.start.x, field.start.y);
		printf("Goal: %d, %d\n", field.goal.x, field.goal.y);
	}
	get_best_move(&field, heatmap, walkmap);

	int	i = 0;
	while (i < field.height)
	{
		free(field.field[i]);
		i++;
	}
	free(field.field);

	i = 0;
	while (walkmap[i])
	{
		free(walkmap[i]);
		i++;
	}
	free(walkmap);

	i = 0;
	while (heatmap[i])
	{
		free(heatmap[i]);
		i++;
	}
	free(heatmap);

	return (0);
}
