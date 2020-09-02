/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:20:58 by gdp               #+#    #+#             */
/*   Updated: 2020/03/25 17:32:48 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	c_char;

	if (c < 0)
		c += 256;
	c_char = c;
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((unsigned char *)dest)[i] == c_char)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
