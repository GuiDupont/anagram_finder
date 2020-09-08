/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:43:12 by gdupont           #+#    #+#             */
/*   Updated: 2020/05/13 14:44:59 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	double	ft_atof_2(double neg, char *s)
{
	int				i;
	double			res;
	unsigned long	dec;

	i = 0;
	res = 0.f;
	while (ft_isdigit(s[i]) && s[i])
	{
		res *= 10;
		res += s[i++] - '0';
	}
	dec = 10.f;
	if (s[i] == '.' && s[i + 1])
		i++;
	while (ft_isdigit(s[i]) && s[i])
	{
		res += (s[i++] - '0') / (float)dec;
		dec *= 10;
	}
	return (res * neg);
}

double			ft_atof(char *s)
{
	int		i;
	double	neg;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ')
		i++;
	neg = 1;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	return (ft_atof_2(neg, &s[i]));
}
