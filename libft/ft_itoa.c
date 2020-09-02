/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:18:00 by gdupont           #+#    #+#             */
/*   Updated: 2020/04/28 00:26:46 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*malloc_dest(long n, int *count)
{
	char	*dest;

	if (n < 0)
	{
		n = -n;
		*count = *count + 1;
	}
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

char		*ft_itoa(int n)
{
	long	n_long;
	char	*dest;
	int		count;

	n_long = n;
	count = 1;
	if (!(dest = malloc_dest(n_long, &count)))
		return (NULL);
	if (n_long < 0)
	{
		dest[0] = '-';
		n_long = -n_long;
	}
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
