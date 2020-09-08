/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:19:41 by gdupont           #+#    #+#             */
/*   Updated: 2020/04/28 00:39:37 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	if (!src)
		return (0);
	while (src[count] != '\0')
		count++;
	if (!dstsize)
		return (count);
	if (!dst)
		return (0);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
