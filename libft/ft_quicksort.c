/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:32:34 by gdupont           #+#    #+#             */
/*   Updated: 2020/05/07 12:38:41 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	partition(int *array, int index_min, int size)
{
	int i;
	int y;

	if (index_min >= 0)
		i = index_min - 1;
	else
		i = -1;
	y = index_min;
	while (y < size - 1)
	{
		if (array[y] <= array[size - 1])
		{
			i++;
			ft_swap(&array[i], &array[y]);
		}
		y++;
	}
	i++;
	ft_swap(&array[size - 1], &array[i]);
	return (i);
}

void		ft_quicksort(int *array, int index_min, int size)
{
	int i;

	i = partition(array, index_min, size);
	if ((size - (i + 1)) > 1)
		ft_quicksort(array, i + 1, size);
	if (((1 + i) - index_min) > 1)
		ft_quicksort(array, index_min, i);
}
