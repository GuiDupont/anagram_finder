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

char	*erase_whitespaces_and_cap_from_str(char *line)
{
	char		**temp;
	int			i = -1;

	while(line[i++])
	{
		if (line[i] >= 'A' && line[i] <= 'Z')
			line[i] += 23;
		else if (line[i] == '\t')
			line[i] = ' ';
	}
	temp = ft_split(line, ' ');
	free(line);
	line = ft_strjoin2d(temp);
	ft_free_split(temp);
	return (line);
}

void	test_combinations(char *s, t_word *ordered[10])
{
	int		len;
	char	*candidate;
	t_word	*save_adj;
	t_word	*save_noun;
	t_word	*save_verb;
	t_word	*save_noun_2;

	len = ft_strlen(s);
	save_noun = ordered[NOUN];
	while(save_noun)
	{
		save_verb = ordered[VERB];
		while (save_verb)
		{
			save_adj = ordered[ADJ];
			while (save_adj)
			{
				save_noun_2 = ordered[NOUN];
				while (save_noun_2)
				{
					if ((save_noun->len + save_adj->len + save_verb->len + save_noun_2->len) == len)
					{
						candidate = ft_strjoin_undefined(4, save_noun->word, save_verb->word, save_adj->word, save_noun_2->word);
						ft_putstr(candidate);
						//ft_putchar('\n');
						//if (ft_is_anagram(s, candidate, PARTIAL_NOT_ACCEPTED))
						//	printf("Here is a working anagram: %s %s\n", save_noun->word, save_adj->word);
						free(candidate);
					}
					save_noun_2 = save_noun_2->next;
				}
				save_adj = save_adj->next;
			}
			save_verb = save_verb->next;
		}
		save_noun = save_noun->next;
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_global	global;
	char		*line;
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
		if (line[0] == 'x' && !line[1])
			return (0);
		line = erase_whitespaces_and_cap_from_str(line);	
		global.solutions = find_anagrams(line, global.dico, PARTIAL_NOT_ACCEPTED);
		global.partial_solutions = find_anagrams(line, global.dico, PARTIAL_ACCEPTED);
		lst_to_nature_ordered(global.partial_solutions, global.partial_solutions_by_nature);
		//ft_print_lst(global.solutions, "Those are the complete solutions: ");
		ft_print_lst(global.partial_solutions, "Those are the partial solutions: ");
		//ft_print_lst(lobal.partial_solutions_by_nature[NOUN], "Those are the partial solutions which are NOUN: ");
		test_combinations(line, global.partial_solutions_by_nature);
		free(line);
		ft_lstdel(&(global.solutions));
		ft_lstdel(&(global.partial_solutions));
		ft_del_partial_solution_by_nature(global.partial_solutions_by_nature);
	}
	close(fd);
	return (0);
}

//Nom verbe adj nom

