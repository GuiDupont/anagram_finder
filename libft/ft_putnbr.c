/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:40:27 by gdupont           #+#    #+#             */
/*   Updated: 2020/03/18 20:22:03 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		nb_long = -nb_long;
		ft_putchar('-');
	}
	if (nb_long > 9)
		ft_putnbr(nb_long / 10);
	ft_putchar(nb_long % 10 + '0');
}
