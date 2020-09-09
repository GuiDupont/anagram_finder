/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:24:03 by user42            #+#    #+#             */
/*   Updated: 2020/05/01 17:14:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *buffer, int size)
{
	if (!buffer)
		return ;
	while (size--)
	{
		((char *)buffer)[size] = '\0';
	}
}

int		char_is_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		put_buff_in_line(int fd, char *buff, char **line)
{
	int read_return;

	while (1)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return < 0)
			return (-1);
		else
		{
			if (!(increase_line_size(line, ft_strlen_char(buff, '\n'))))
				return (-1);
			ft_strcat_char(*line, buff, '\n');
			if (char_is_in_str(buff, '\n') >= 0)
			{
				update_previous_buffer(buff);
				if (read_return)
					return (1);
			}
			if (read_return == 0)
				return (0);
		}
	}
}

int		fill_line(int fd, char *buff, char **line)
{
	if (char_is_in_str(buff, '\n') >= 0)
	{
		if (!(increase_line_size(line, ft_strlen_char(buff, '\n'))))
			return (-1);
		ft_strcpy_char(*line, buff, '\n');
		update_previous_buffer(buff);
		return (1);
	}
	else
	{
		if (!(increase_line_size(line, ft_strlen_char(buff, '\0'))))
			return (-1);
		ft_strcpy_char(*line, buff, '\0');
		return (put_buff_in_line(fd, buff, line));
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char buff[BUFFER_SIZE + 1];

	if (!line)
		return (-1);
	if (fd < 0 || fd > 256 || BUFFER_SIZE > 100000000 || BUFFER_SIZE <= 0)
	{
		*line = NULL;
		return (-1);
	}
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	ft_bzero(*line, 1);
	return (fill_line(fd, &buff[0], line));
}
