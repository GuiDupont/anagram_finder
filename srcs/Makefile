NAME= anagram_finder
CC= gcc
CFLAGS= -Wall -Wextra -Werror
OBJS= ${SRCS:.c=.o}
SRCS= \
	ft_is_anagram.c  \
	lst_management.c \
	main_test.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re