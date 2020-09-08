/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:18:00 by gdupont           #+#    #+#             */
/*   Updated: 2020/04/30 19:25:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*malloc_dest(unsigned long int n, int *count)
{
	char	*dest;

	while (n >= 10)
	{
		n = n / 10;
		*count = *count + 1;
	}
	if (!(dest = malloc(sizeof(*dest) * (*count + 1))))
		return (NULL);
	dest[*count] = '\0';
	return (dest);
}

char		*ft_itoa_u(unsigned int n)
{
	unsigned long int	n_long;
	char				*dest;
	int					count;

	n_long = n;
	count = 1;
	if (!(dest = malloc_dest(n_long, &count)))
		return (NULL);
	count--;
	while (n_long > 9)
	{
		dest[count] = n_long % 10 + '0';
		n_long = n_long / 10;
		count--;
	}
	dest[count] = n_long % 10 + '0';
	return (dest);
}
