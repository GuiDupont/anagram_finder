/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:24:39 by gdp               #+#    #+#             */
/*   Updated: 2020/04/28 16:43:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_set(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

static int	begin_index(char const *s, char const *set)
{
	int i;

	i = 0;
	while (is_set(set, s[i]) == 1)
		i++;
	return (i);
}

static int	end_index(char const *s, char const *set)
{
	int e;

	e = 0;
	while (s[e])
		e++;
	while (is_set(set, s[e - 1]) == 1)
		e--;
	return (e);
}

char		*ft_strtrim(char const *s, char const *set)
{
	int		b_i;
	int		e_i;
	int		d;
	char	*dest;

	if (!s || !set)
		return (NULL);
	b_i = begin_index(s, set);
	e_i = end_index(s, set);
	if (e_i < b_i)
		b_i = 0;
	if (!(dest = malloc(sizeof(*dest) * (e_i - b_i + 1))))
		return (NULL);
	d = 0;
	while ((b_i + d) < e_i)
	{
		dest[d] = s[b_i + d];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
