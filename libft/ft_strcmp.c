/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:22:46 by gdupont           #+#    #+#             */
/*   Updated: 2020/03/18 20:22:58 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char const *s1, char const *s2)
{
	int n;
	int result;

	n = 0;
	while (s1[n] || s2[n])
	{
		if (s1[n] != s2[n])
		{
			result = (s1[n] - s2[n]);
			if (s1[n] < 0)
				return (result + 256);
			else if (s2[n] < 0)
				return (result - 256);
			else
				return (result);
		}
		n++;
	}
	return (0);
}
