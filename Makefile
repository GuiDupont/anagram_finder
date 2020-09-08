# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdupont <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 13:20:33 by gdupont           #+#    #+#              #
#    Updated: 2020/09/08 13:47:36 by gdupont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = anagram_finder

CC = gcc

OBJS = $(SRCS:.c =.o)

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = srcs

LIBFT = libft

SRCS_LIST = ft_is_anagram.c

SRCS = $(addprefix ${PATH_SRCS}/, ${SRCS_LIST})

all : $(NAME)

$(NAME) :	$(OBJS)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)
	make clean -s -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus
