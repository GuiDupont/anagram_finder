#include "../includes/anagram.h"

t_word	*ft_lst_word_new(void *content, int len, char *nature)
{
	t_word *final;

	if (!(final = malloc(sizeof(t_word))))
		return (NULL);
	final->word = content;
	if (content && final->word[0] >= 'A' && final->word[0] <= 'Z')
		final->word[0] += 32;
	final->nature = nature;
	final->next = NULL;
	return (final);
}


void	add_elem_to_end_lst(t_word *lst, t_word *word)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = ft_lst_word_new(word->word, word->len, word->nature);
}


void	lst_to_nature_ordered(t_word *lst, t_word *ordered[10])
{
	while (lst)
	{
		if (!lst->nature)
			puts("no_nature\n");
		else if (ft_strequ(lst->nature, "n."))
			add_elem_to_end_lst(ordered[NOUN], lst);
		else if (ft_strequ(lst->nature, "adj."))
			add_elem_to_end_lst(ordered[ADJ], lst);
		else if (ft_strequ(lst->nature, "adv."))
			add_elem_to_end_lst(ordered[ADV], lst);
		else if (ft_strequ(lst->nature, "abbr."))
			add_elem_to_end_lst(ordered[ABBR], lst);
		else if (ft_strequ(lst->nature, "conj."))
			add_elem_to_end_lst(ordered[CONJ], lst);
		else if (ft_strequ(lst->nature, "var."))
			add_elem_to_end_lst(ordered[VAR], lst);
		else if (ft_strequ(lst->nature, "prep."))
			add_elem_to_end_lst(ordered[PREP], lst);
		else if (ft_strequ(lst->nature, "pron."))
			add_elem_to_end_lst(ordered[PRON], lst);
		else if (ft_strequ(lst->nature, "v."))
			add_elem_to_end_lst(ordered[VERB], lst);
		else
			puts(lst->nature);
		lst = lst->next;
	}
}

int		check_if_valid_nature(char *s)
{
	if (!s)
		return (0);
	if (ft_strequ(s, "v.")
			|| ft_strequ(s, "n.")
			|| ft_strequ(s, "adj.")
			|| ft_strequ(s, "adv.")
			|| ft_strequ(s, "abbr.")
			|| ft_strequ(s, "conj.")
			|| ft_strequ(s, "var.")
			|| ft_strequ(s, "prep.")
			|| ft_strequ(s, "pron.")
			|| ft_strequ(s, "-n.")
			|| ft_strequ(s, "-v.")
			|| ft_strequ(s, "-adj.")
			|| ft_strequ(s, "-adv.")
			|| ft_strequ(s, "-conj."))
		return (1);
	return (0);
}

t_word	*put_words_in_lst(int fd)
{
	t_word	*final;
	t_word	*temp;
	char	**line2d;
	char	*line;

	final = ft_lst_word_new(NULL, 0, NULL);
	temp = final;
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
			line2d = ft_split(line, ' ');
		if (line2d[0] && ft_str_is_alpha(line2d[0]) && check_if_valid_nature(line2d[1]))
		{
			temp->next = ft_lst_word_new(ft_strdup(line2d[0]), ft_strlen(line2d[0]), ft_strdup(line2d[1]));
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
		if (str && lst->word)
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


void	ft_del_partial_solution_by_nature(t_word **lst)
{
	int i = 0;

	while (lst[i])
	{
		ft_lstdel(&(lst[i]->next));
		i++;
	}
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
