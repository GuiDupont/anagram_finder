#include "libft.h"

char	*ft_strjoin_undefined(unsigned int nb, ...)
{
	va_list ap;
	char			*result;
	char			*temp;
	unsigned	int	i;
	char			*next_string;

	i = 0;
	va_start(ap, nb);
	result = ft_strdup("\0");
	while (i < nb)
	{
		next_string = va_arg(ap, char*);
		temp = result;
		result = ft_strjoin(result, next_string);
		free(temp);
		i++;
	}
	return (result);
}