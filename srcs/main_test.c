#include "../includes/lib.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_global	global;
	char		*line;
	char		**temp;

	if (argc != 1)
		return (0);
	fd = open("dico/english2.txt", O_RDONLY);
	if (fd <= 0)
		return (0);
	global.dico = put_words_in_lst(fd);
	while (1)
	{
		ft_putstr("Write a sentence, we will show you some anagrams:\n");
		get_next_line(1, &line);
		temp = ft_split(line, ' ');
		free(line);
		line = ft_strjoin2d(temp);
		ft_free_split(temp);
		global.solutions = find_anagrams(line, global.dico);
		global.partial_solutions = find_partial_anagrams(line, global.dico);
		ft_print_lst(global.solutions, "Those are the complete solutions: ");
		print_partial_solutions(global.partial_solutions);
		free(line);
		ft_lstdel(&(global.solutions));
		ft_lstdel(&(global.partial_solutions));
	}
	close(fd);
	return (0);
}
