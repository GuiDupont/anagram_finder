/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:21:07 by gdp               #+#    #+#             */
/*   Updated: 2020/03/18 20:21:10 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && i < n)
	{
		if (i == n - 1)
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
