/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <gdp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:45:24 by gdupont           #+#    #+#             */
/*   Updated: 2020/04/28 00:00:12 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, unsigned int n)
{
	unsigned int i;
	unsigned int len_to_find;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (!to_find[0])
		return ((char *)str);
	if (!(str[0]) || n == 0)
		return (NULL);
	while (str[i] && i + len_to_find <= n)
	{
		if (ft_strncmp(&str[i], to_find, len_to_find) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
