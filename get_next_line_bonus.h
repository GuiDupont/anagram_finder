/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:24:10 by user42            #+#    #+#             */
/*   Updated: 2020/04/28 12:27:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
