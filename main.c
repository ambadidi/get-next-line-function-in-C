#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	char	*line;
	//char	*line1;
	int	fd = open("test.txt", O_RDONLY);
	line = get_next_line(1);
	//int fd1 = open("test0.txt", O_RDONLY);
	//line1 = get_next_line(1);
	while (line != NULL)// && line1 != NULL)
	{
		printf("%s", line);
		//printf("%s", line1);
		free(line);
		//free(line1);
		line = get_next_line(fd);
		//line1 = get_next_line(fd1);
	}
	close (fd);
	//close(fd1);
	return (EXIT_SUCCESS);
}