/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_single_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 23:35:35 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 14:02:10 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_single_char(char c, int *pft)
{
	ft_putchar(c);
	*pft += 1;
	return (1);
}

int	no_conf(void)
{
	return (1);
}
