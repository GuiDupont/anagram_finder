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

char	*extract_nature_from_line(char *line)
{
	char	*nature;
	char	*ptr_dot;
	char	*ptr_comma;
	int		len;

	ptr_comma = ft_strchr(line, ',');
	ptr_dot = ft_strchr(line, '.');
	if (!ptr_comma || !ptr_dot)
		return (NULL);
	len = ptr_dot - ptr_comma - 2;
	if (!(nature = malloc(sizeof(*nature) * (len + 1))))
		return (NULL);
	strncpy(nature, ptr_comma + 1, len);
	nature[len] = '\0';
	return (nature);
}


t_word	*put_words_in_lst(int fd)
{
	t_word	*final;
	t_word	*temp;
	char	*line;

	get_next_line(fd, &line);
	final = ft_lst_word_new(line, ft_strlen(line));
	printf("dans la fonction : %p\n", final);
	temp = final;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		printf("line : |%s|\n", line);
		if (ft_str_is_cap(line))
		{
			printf("line : |%s|\n", line);
			temp->next = ft_lst_word_new(line, ft_strlen(line));
			get_next_line(fd, &line);
			temp->next->nature = extract_nature_from_line(line);
			temp = temp->next;
		}
	}
	printf("dans la fonction apres: %s\n", final->word);
	return (final);
}

void	ft_print_lst(t_word *lst, char *str)
{
	while (lst)
	{

		printf("%s %s\n", str, lst->word);
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
