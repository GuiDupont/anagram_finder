/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:22:46 by gdupont           #+#    #+#             */
/*   Updated: 2020/02/12 12:14:24 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned int nb)
{
	unsigned int	i;
	int				result;

	i = 0;
	if (nb == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < nb - 1)
		i++;
	result = s1[i] - s2[i];
	if (s1[i] < 0)
		result += 256;
	if (s2[i] < 0)
		result -= 256;
	return (result);
}
