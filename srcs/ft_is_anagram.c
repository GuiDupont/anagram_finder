#include "../includes/lib.h"

static int	ft_place_is_free(int nb, char *array)
{
	if (array[nb] == 0)
		return (1);
	return (0);
}

int			ft_is_anagram(char *word, char *candidate, int partial_accepted)
{
	int		i;
	int		y;
	char	taken[100];

	i = -1;
	ft_memset(taken, 0, 100);
	if ((!partial_accepted && ft_strlen(word) != ft_strlen(candidate)) || 
	(partial_accepted && ft_strlen(word) == ft_strlen(candidate)) ||
	 (ft_strlen(word) == 1 && word[0] != 'i'))
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

void	print_partial_solutions(t_word *partial_solutions)
{
	ft_print_lst(partial_solutions, "These are the partial solutions: ");
}

