/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:14:13 by gdupont           #+#    #+#             */
/*   Updated: 2020/04/28 01:13:24 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(const char *str)
{
	int		n;
	int		negative;
	long	result;

	negative = 1;
	n = 0;
	result = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' || str[n] == '\v'
	|| str[n] == '\f' || str[n] == '\r')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			negative = -negative;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
		result = result * 10 + (str[n++] - '0');
	if (result < 0 && negative > 0)
		return (-1);
	else if (result < 0 && negative < 0 && result * negative != -2147483648)
		return (0);
	return (result * negative);
}
