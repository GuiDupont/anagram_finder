/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_to_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:01:39 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 13:52:14 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	u_to_x_len(unsigned int origin)
{
	int		len;

	len = 1;
	while (origin >= 16)
	{
		origin /= 16;
		len++;
	}
	return (len);
}

char		*u_to_x(unsigned int nb, char c)
{
	char	*ref;
	char	*final;
	int		len_final;

	len_final = u_to_x_len(nb);
	if (!(final = malloc(sizeof(*final) * len_final + 1)))
		return (NULL);
	ref = (c == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	final[len_final] = '\0';
	len_final--;
	while (nb >= 16)
	{
		final[len_final] = ref[nb % 16];
		len_final--;
		nb /= 16;
	}
	final[len_final] = ref[nb];
	return (final);
}
