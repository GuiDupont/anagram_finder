/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:20:55 by gdp               #+#    #+#             */
/*   Updated: 2020/04/27 23:13:42 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(int size)
{
	void	*buffer;

	if (!(buffer = malloc(sizeof(*buffer) * size)))
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}
