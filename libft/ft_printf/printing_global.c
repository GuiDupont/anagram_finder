/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:42:36 by user42            #+#    #+#             */
/*   Updated: 2020/05/06 18:23:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_conf(t_conf *conf, int *pft)
{
	if (conf->symb == 'c')
		ft_print_c(conf, pft);
	else if (conf->symb == 's')
		ft_print_s(conf, pft);
	else if (conf->symb == 'd' || conf->symb == 'i')
		ft_print_d_i(conf, pft);
	else if (conf->symb == 'x' || conf->symb == 'X')
		ft_print_x(conf, pft);
	else if (conf->symb == 'p')
		ft_print_p(conf, pft);
	else if (conf->symb == 'u')
		ft_print_u(conf, pft);
	else if (conf->symb == '%')
		ft_print_percentage(conf, pft);
}
