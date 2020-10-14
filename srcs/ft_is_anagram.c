#include "../includes/lib.h"

static int	ft_place_is_free(int nb, char *array)
{
	if (array[nb] == 0)
		return (1);
	return (0);
}

void		ft_swap_str(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}


t_word	*find_anagrams(char *word, t_word *dico, int partial_anagrams)
{
	t_word	*solutions;
	t_word	*first_elem;
	int		flag_first;

			// same issue here we want to send the first element of our solutions
			// so I used another triks which is to use a 'flag'. This int will let us know
			// if we already created the first element or not.  
	flag_first = 0;
	first_elem = NULL;
	while (dico)	// we are going through our linked list of words
	{
		if (ft_is_anagram(word, dico->word, partial_anagrams) == 1)	// if they are anagrams we want to add the word to our solution list
		{
			if (flag_first == 0) 	// if it is the first element then we will store it in the pointer firs_elem
			{						// and set the flag to 1;
				solutions = ft_lst_word_new(dico->word, dico->len);
				flag_first = 1;
				first_elem = solutions;
			}
			else					// if it not the first element we can do it normally
			{
				solutions->next = ft_lst_word_new(dico->word, dico->len);
				solutions = solutions->next;
			}
		}
		dico = dico->next;
	}
	return (first_elem); 
}

int			ft_is_anagram(char *word, char *candidate, int partial_accepted)
{
	int		i;
	int		y;
	char	taken[100];

	i = -1;
	ft_memset(taken, 0, 100);
	if (partial_accepted)
		ft_swap_str(&word, &candidate);
	if ((!partial_accepted && ft_strlen(word) != ft_strlen(candidate)) || 
	(partial_accepted && ft_strlen(word) == ft_strlen(candidate)) ||
	 (ft_strlen(word) == 1 && word[0] != 'i' && word[0] != 'a'))
		return (0);
	if (!ft_strcmp(word, candidate))
		return (0);
	while (word[++i])
	{
		y = -1;
		while (candidate[++y])
		{
			if (word[i] == candidate[y] && ft_place_is_free(y, &taken[0]))
			{
				taken[y] = 1;
				break ;
			}
		}
		if (!candidate[y])
			return (0);
	}
	return (1);
}