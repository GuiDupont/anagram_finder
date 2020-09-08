/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:29:24 by gdupont           #+#    #+#             */
/*   Updated: 2020/02/20 16:28:18 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	int		n;
	int		i;
	char	*dest;

	n = 0;
	i = 0;
	while (s1[n])
		n++;
	dest = malloc(sizeof(*dest) * (n + 1));
	if (dest == NULL)
		return (0);
	while (i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
