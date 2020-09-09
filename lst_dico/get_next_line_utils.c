/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:02:28 by user42            #+#    #+#             */
/*   Updated: 2020/04/28 23:36:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat_char(char *dest, const char *src, char c)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && src[j] != c)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen_char(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strcpy_char(char *dest, char *src, char c)
{
	int i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		increase_line_size(char **line, int size_sup)
{
	char	*new;
	int		line_len;

	if (!size_sup)
		return (1);
	line_len = ft_strlen_char(*line, '\0');
	if (!(new = malloc(sizeof(*new) * (line_len + size_sup + 1))))
		return (0);
	ft_strcpy_char(new, *line, '\0');
	if (*line)
		free(*line);
	*line = new;
	return (1);
}

void	update_previous_buffer(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return ;
	while (str[i] != '\n')
		i++;
	i++;
	ft_strcpy_char(str, &str[i], '\0');
}
