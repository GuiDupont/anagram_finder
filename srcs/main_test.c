#include "../includes/anagram.h"


void	set_partial_ordered_solutions_to_null(t_word *to_set_to_null[9])
{
	int i = 0;

	while (i < 9)
	{
		to_set_to_null[i] = ft_lst_word_new(NULL, 0, NULL);
		i++;
	}
}

//Nom verbe adj nom

int	main(int argc, char **argv)
{
	int			fd;
	t_global	global;
	char		*line;
	char		**temp;
	t_word		*nature_list;

	if (argc != 1)
		return (0);
	fd = open("dico/dico_nature.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	global.dico = put_words_in_lst(fd);
	set_partial_ordered_solutions_to_null(global.partial_solutions_by_nature);
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
		lst_to_nature_ordered(global.partial_solutions, global.partial_solutions_by_nature);
		ft_print_lst(global.solutions, "Those are the complete solutions: ");
		ft_print_lst(global.partial_solutions, "Those are the partial solutions: ");
		ft_print_lst(global.partial_solutions_by_nature[NOUN], "Those are the partial solutions which are NOUN: ");
		free(line);
		ft_lstdel(&(global.solutions));
		ft_lstdel(&(global.partial_solutions));
		ft_del_partial_solution_by_nature(global.partial_solutions_by_nature);
	}
	close(fd);
	return (0);
}
