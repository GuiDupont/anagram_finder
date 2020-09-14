#include "get_next_line.h"
BUFFER_SIZE=12

int main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}	
