/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdp <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:20:45 by gdp               #+#    #+#             */
/*   Updated: 2020/04/19 02:57:16 by gdp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *final;

	if (!(final = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	final->content = content;
	final->next = NULL;
	return (final);
}
