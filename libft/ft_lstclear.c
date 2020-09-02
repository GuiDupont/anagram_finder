/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:20:22 by gdp               #+#    #+#             */
/*   Updated: 2020/03/18 20:20:26 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void*))
{
	t_list *temp;
	t_list *temp2;

	temp = *list;
	while (temp != NULL)
	{
		temp2 = temp->next;
		ft_lstdelone(temp, (*del));
		temp = temp2;
	}
	*list = NULL;
}
