/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:40:27 by gdupont           #+#    #+#             */
/*   Updated: 2020/03/18 20:22:20 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		nb_long = -nb_long;
		ft_putchar_fd('-', fd);
	}
	if (nb_long > 9)
		ft_putnbr_fd(nb_long / 10, fd);
	ft_putchar_fd(nb_long % 10 + '0', fd);
}
