#include "dash.h"
#include <fcntl.h>

void	translate_nbrs(Field *t_field)
{
	char **matrix = t_field->field;

	for (int x = 0; x < t_field->width; x++)
	{
		for (int y = 0; y < t_field->height; y++)
		{
			if (matrix[y][x] >= '1' && matrix[y][x] <= '9')
				matrix[y][x] -= '0';
		}
	}
}

Field	parse_file(char *filename)
{
	int		fd;
	char	*line;
	char	**field;
	int		ind;
	Field	result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: could not open file");
		exit(1);
	}
	ind = 0;
	field = (char **)malloc(1 * sizeof(char *));
	while ((line = get_next_line(fd)))
	{
		field = (char **)realloc(field, (ind + 2) * sizeof(char *));
		field[ind] = ft_strtrim(line, "\n");
		free(line);
		ind++;
		field[ind] = NULL;
	}
	result.field = field;
	result.height = ind;
	result.width = ft_strlen(field[0]);
	translate_nbrs(&result);
	result.start = get_start(result);
	result.goal = get_goal(result);
	return (result);
}
