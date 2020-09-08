/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:40:41 by gdupont           #+#    #+#             */
/*   Updated: 2020/04/28 00:42:03 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len_dest;

	if (!s1 || !s2)
		return (NULL);
	len_dest = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc(sizeof(*dest) * (len_dest + 1))))
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
