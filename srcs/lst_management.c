#include "../includes/anagram.h"

t_word	*ft_lst_word_new(void *content, int len)
{
	t_word *final;

	if (!(final = malloc(sizeof(t_word))))
		return (NULL);
	final->word = content;
	if (content && final->word[0] >= 'A' && final->word[0] <= 'Z')
		final->word[0] += 32;
	final->nature = NULL;
	final->next = NULL;
	return (final);
}

int		check_if_valid_nature(char *s)
{
	if (!s)
		return (0);
	if (ft_strequ(s, "v.") 
			|| ft_strequ(s, "-v.")
			|| ft_strequ(s, "n.")
			|| ft_strequ(s, "-n.")
			|| ft_strequ(s, "adj.")
			|| ft_strequ(s, "-adj.")
			|| ft_strequ(s, "-adv.")
			|| ft_strequ(s, "adv.")
			|| ft_strequ(s, "abbr.")
			|| ft_strequ(s, "-conj.")
			|| ft_strequ(s, "conj.")
			|| ft_strequ(s, "var.")
			|| ft_strequ(s, "prep.")
			|| ft_strequ(s, "pron."))
		return (1);
	return (0);
		
}

t_word	*put_words_in_lst(int fd)
{
	t_word	*final;
	t_word	*temp;
	char	**line2d;
	char	*line;

	get_next_line(fd, &line);
	final = ft_lst_word_new(line, ft_strlen(line));
	temp = final;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
			line2d = ft_split(line, ' ');
		if (line2d[0] && ft_str_is_alpha(line2d[0]) && check_if_valid_nature(line2d[1]))
		{
			temp->next = ft_lst_word_new(ft_strdup(line2d[0]), ft_strlen(line2d[0]));
			if (line2d[1])
				temp->nature = ft_strdup(line2d[1]);
			temp = temp->next;
		}
		ft_free_split(line2d);
		free(line);
		line = NULL;
		line2d = NULL;
	}
	return (final);
}

void	ft_print_lst(t_word *lst, char *str)
{
	while (lst)
	{
		if (str)
			ft_putstr(str);
		if (lst->word)
			ft_putstr(lst->word);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void	ft_lstdel(t_word **lst)
{
	t_word	**backup;
	
	if (!lst || !(*lst))
		return ;
	backup = lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(*lst);
	}
	free(*backup);
	backup = NULL;
}

int		ft_lstsize(t_word *lst)
{
	int i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
