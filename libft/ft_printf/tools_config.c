/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:04:33 by user42            #+#    #+#             */
/*   Updated: 2020/05/06 17:34:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	initialize_conf(t_conf *conf)
{
	conf->str = NULL;
	conf->width = 0;
	conf->l_align = 0;
	conf->precis = 0;
	conf->dot = 0;
	conf->zero = 0;
	conf->neg = 0;
	conf->c = '\0';
	conf->symb = '\0';
}

int		find_flag(char const *str, char c)
{
	int i;

	i = 1;
	while (ft_strchr(FLAGS, str[i]))
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	set_width(char const *str, t_conf *conf)
{
	int		i;
	char	*temp;

	i = 0;
	if (!(temp = malloc(sizeof(*temp) * (ft_strlen(str) + 1))))
		return ;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	i = 1;
	while (temp[i] == '-' || temp[i] == '0')
		i++;
	conf->width = ft_atoi(&temp[i]);
	free(temp);
}

void	delete_1st_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
}

int		check_zero(char const *str)
{
	int i;

	i = 1;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
