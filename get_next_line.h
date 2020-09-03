/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltun <aaltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:24:15 by user42            #+#    #+#             */
/*   Updated: 2020/09/03 15:52:49 by aaltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 12

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

char	*ft_strcat_char(char *dest, const char *src, char c);
int		ft_strlen_char(const char *str, char c);
char	*ft_strcpy_char(char *dest, char *src, char c);
int		increase_line_size(char **line, int size_sup);
void	update_previous_buffer(char *str);
int		get_next_line(int fd, char **line);

#endif
