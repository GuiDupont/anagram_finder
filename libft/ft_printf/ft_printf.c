/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:04:38 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 13:53:12 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg;
	int		pft;

	if (!str)
		return (0);
	va_start(arg, str);
	pft = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_conf_valid(&str[i]))
			i += valid_conf(&str[i], &arg, &pft);
		else if (str[i] == '%')
			i += no_conf();
		else
			i += print_single_char(str[i], &pft);
	}
	va_end(arg);
	return (pft);
}
