/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:22:30 by gdupont           #+#    #+#             */
/*   Updated: 2020/05/12 17:24:56 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_len(char **array)
{
	int	count;

	count = 0;
	if (!array)
		return (count);
	while (array[count])
		count++;
	return (count);
}