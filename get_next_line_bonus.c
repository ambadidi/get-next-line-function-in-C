#include "get_next_line_bonus.h"

char	*get_line(char *src, int fd)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr(src, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		src = ft_strjoin(src, buffer);
	}
	free(buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line[fd] = get_line(next_line[fd], fd);
	if (next_line[fd] == NULL)
		return (NULL);
	line = ft_extract_line(next_line[fd]);
	next_line[fd] = ft_rest(next_line[fd]);
	if (line[0] == '\0')
	{
		free(next_line[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}