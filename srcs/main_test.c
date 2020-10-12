#include "../includes/lib.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_global	global;
	char		*line;
	char		**temp;

	if (argc != 1)
		return (0);
	fd = open("dico/english_dico2.txt", O_RDONLY);
	if (fd <= 0)
		return (0);
	global.dico = put_words_in_lst(fd);
	printf("globaldico : %p", global.dico);
	ft_print_lst(global.dico, "\ndico:");
	while (1)
	{
		ft_putstr("Write a sentence, we will show you some anagrams:\n");
		get_next_line(1, &line);
		temp = ft_split(line, ' ');
		free(line);
		line = ft_strjoin2d(temp);
		ft_free_split(temp);
		global.solutions = find_anagrams(line, global.dico, PARTIAL_NOT_ACCEPTED);
		global.partial_solutions = find_anagrams(line, global.dico, PARTIAL_ACCEPTED);
		ft_print_lst(global.solutions, "Those are the complete solutions: ");
		ft_print_lst(global.partial_solutions, "Those are the partial solutions: ");
		free(line);
		ft_lstdel(&(global.solutions));
		ft_lstdel(&(global.partial_solutions));
	}
	close(fd);
	return (0);
}
