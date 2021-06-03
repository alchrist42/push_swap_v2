#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int	result;
	int	i;

	i = 0;
	*line = malloc(BUFFER_SIZE);
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE - 1
		&& (result = read(fd, *line + i, CONTENT_MIN_SIZE)))
	{
		if (result == -1)
			return (-1);
		if ((*line)[i] == '\n')
			break ;
		i++;
	}
	(*line)[i] = 0;
	return ((result != 0));
}
