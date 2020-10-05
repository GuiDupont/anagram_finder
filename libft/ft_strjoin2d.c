#include "libft.h"

char *ft_strjoin2d(char **cmd)
{
	int		i;
	int		k;
	char	*line;

	i = -1;
	k = 0;
	while (cmd[++i])
		k += ft_strlen(cmd[i]);
	if (!(line = malloc(sizeof(*line) * k + 1)))
		return (NULL);
	line[0] = '\0';
	while (i--)
		ft_strcat(line, cmd[i]);
	return (line);
}