/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <gdp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:00:24 by gdp               #+#    #+#             */
/*   Updated: 2020/04/28 01:18:30 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void *dest;

	if (!(dest = malloc((nmemb) * size)))
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
