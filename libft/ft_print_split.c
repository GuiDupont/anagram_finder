#include "libft.h"

void	ft_print_split(char **s)
{
	int i;

	if (!s || !s[0])
		return ;
	i = 0;
	while (s[i])
	{
		ft_putstr(s[i]);
		ft_putchar('\n');
		i++;
	}
}
