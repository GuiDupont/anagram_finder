/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:45:24 by gdupont           #+#    #+#             */
/*   Updated: 2020/02/12 12:22:52 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	int len_to_find;
	int n;

	len_to_find = 0;
	n = 0;
	if (!(to_find[0]))
		return ((char *)str);
	if (!(str[0]))
		return (0);
	while (to_find[len_to_find])
		len_to_find++;
	while (str[n])
	{
		if (ft_strncmp(to_find, &str[n], len_to_find) == 0)
			return ((char *)&str[n]);
		n++;
	}
	return (0);
}
