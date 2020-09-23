#include "../includes/lib.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_word	*words;
	t_word	*solutions;

	if (argc != 2)
		return (0);
	fd = open("../dico/english2.txt", O_RDONLY);
	if (fd <= 0)
		return (0);
	words = put_words_in_lst(fd);
	solutions = find_anagrams(argv[1], words);
	while (solutions)
	{
		puts(solutions->content);
		solutions = solutions->next;
	}
	return (0);
}
