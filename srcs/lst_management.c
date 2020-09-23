#include "../includes/lib.h"

t_word  *put_words_in_lst(int fd)
{
    t_word  *final;
    t_word  *temp;
    char    *line;

	get_next_line(fd, &line);
	final = ft_lstnew(line);
	temp = final;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		temp->next = ft_lstnew(line);
		temp = temp->next;
	}	
	return (final);
}

t_word	*find_anagrams(char *word, t_word *all_words)
{
	t_word	*solutions;
	t_word	*first_elem;
	int		flag_first;

	flag_first = 0;
	while(all_words)
	{
		if (ft_is_anagram(word, all_words->content) == 1)
		{
			if (flag_first == 0)
			{
				solutions = ft_lstnew(all_words->content);
				flag_first = 1;
				first_elem = solutions;
			}
			else
			{
				solutions->next = ft_lstnew(all_words->content);
				solutions = solutions->next;
			}

		}
		all_words = all_words->next;
	}
	return (first_elem);
}

