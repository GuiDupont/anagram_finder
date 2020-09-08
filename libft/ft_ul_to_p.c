/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ul_to_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:06:58 by user42            #+#    #+#             */
/*   Updated: 2020/05/06 17:08:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	d_to_p_len(unsigned long origin)
{
	int		len;

	len = 1;
	while (origin >= 16)
	{
		origin /= 16;
		len++;
	}
	len += 2;
	return (len);
}

char		*ft_ul_to_p(unsigned long nb)
{
	char	*ref;
	char	*final;
	int		len_final;

	len_final = d_to_p_len(nb);
	if (!(final = malloc(sizeof(*final) * len_final + 1)))
		return (NULL);
	ft_strcpy(final, "0x");
	ref = "0123456789abcdef";
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
