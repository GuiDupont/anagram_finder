NAME= anagram_finder.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror
OBJS= ${SRCS:.c=.o}
SRCS= \
	srcs/ft_is_anagram.c  \
	srcs/lst_management.c \
	srcs/main_test.c
	
INCLUDES= includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	ar rcs $(NAME) ${OBJS}

-c.o:
	{CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean:
	rm -f $(OBJS) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re