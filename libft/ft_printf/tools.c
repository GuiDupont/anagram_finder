/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:10:13 by user42            #+#    #+#             */
/*   Updated: 2020/05/06 18:37:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			is_conf_valid(char const *str)
{
	int i;

	i = 0;
	if (str[1])
		i++;
	while (str[i] && c_is_flag(str[i]))
		i++;
	if (c_is_symbol(str[i]))
		return (i);
	return (0);
}

char		get_symb(char const *str_global)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, str_global[i]))
		i++;
	return (str_global[i]);
}

int			ft_find_char(char const *str, char c)
{
	int i;

	i = 1;
	while (!(ft_strchr(SYMB, str[i])))
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
