#include "../includes/lib.h"

t_word	*ft_lst_word_new(void *content, int len)
{
	t_word *final;

	if (!(final = malloc(sizeof(t_word))))
		return (NULL);
	final->word = content;
	final->next = NULL;
	return (final);
}

t_word	*put_words_in_lst(int fd)
{
	t_word	*final;
	t_word	*temp;
	char	*line;

	get_next_line(fd, &line);
	final = ft_lst_word_new(line, ft_strlen(line));
	temp = final;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		temp->next = ft_lst_word_new(line, ft_strlen(line));
		temp = temp->next;
	}
	return (final);
}

void	ft_print_lst(t_word *lst, char *str)
{
	while (lst)
	{
		ft_putstr(str);
		puts(lst->word);
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
