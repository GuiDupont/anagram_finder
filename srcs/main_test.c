#include "../includes/lib.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_word	*words;
	t_word	*solutions[3];

	if (argc != 2)
		return (0);
	fd = open("dico/english2.txt", O_RDONLY);
	if (fd <= 0)
		return (0);
	words = put_words_in_lst(fd);
	solutions[0] = find_anagrams(argv[1], words);
	solutions[1] = find_partial_anagrams(argv[1], words);
	solutions[2] = NULL;
	ft_print_lst(solutions[0], "This are the complete solutions: ");
	print_partial_solutions(solutions[1]);
	close(fd);
	return (0);
}
