NAME= anagram
CC= gcc
CFLAGS= -Wall -Wextra -Werror
OBJS= ${SRCS:.c=.o}
SRCS= srcs/ft_is_anagram.c srcs/lst_management.c srcs/main_test.c

LIBFT= libft

all: 
	$(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f srcs/*.o
	make clean -s -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus