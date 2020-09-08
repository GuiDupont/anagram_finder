/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:06:19 by user42            #+#    #+#             */
/*   Updated: 2020/05/06 17:35:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_nb(char c, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_putstr_nb(char *str, int nb)
{
	int i;

	i = 0;
	while (str[i] && i < nb)
	{
		write(1, &str[i], 1);
		i++;
	}
}
