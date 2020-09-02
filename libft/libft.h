/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:05:57 by user42            #+#    #+#             */
/*   Updated: 2020/05/13 14:00:23 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <stdarg.h>
# include <fcntl.h>

# define FLAGS "-0123456789.*\0"
# define SYMB "cspdiuxX%\0"

# define BUFFER_SIZE 30

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(char const *s1, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char const *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, char const *src, unsigned int nb);
char			*ft_strnew(int size);
char			*ft_strnstr(char const *s, char const *to_find, unsigned int n);
char			*ft_strrchr(char const *s1, int c);
char			*ft_strstr(char const *s, char const *to_find);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s, char const *set);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
char			*ft_u_to_x(unsigned int nb, char c);
char			*ft_ul_to_p(unsigned long nb);

char			**ft_split(char const *s, char c);

double			ft_atof(char *s);

int				ft_array_len(char **array);
int				ft_atoi(char const *s);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_lstsize(t_list *lst);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strnequ(const char *s1, const char *s2, unsigned int n);
int				ft_strlen(const char *s);
int				ft_s_isdigit(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

long			abs_l(long i);

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

void			ft_bzero(void *s, int size);
void			ft_free_split(char **array);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *c);
void			ft_putstr_fd(char const *c, int fd);
void			ft_quicksort(int *array, int index_min, int size);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_swap(int *a, int *b);

void			*ft_calloc(unsigned int nmemb, unsigned int size);
void			*ft_memalloc(int size);
void			*ft_memccpy(void *dest, const void *src, int c, unsigned int n);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memchr(const void *s, int c, unsigned int n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memset(void *s, int c, unsigned n);

/*
** FT_PRINTF
*/

typedef	struct	s_conf
{
	char	*str;
	int		width;
	int		precis;
	int		dot;
	int		zero;
	int		l_align;
	int		neg;
	char	symb;
	char	c;
}				t_conf;

int				ft_printf(char const *str, ...);

int				is_conf_valid(char const *str);
void			initialize_conf(t_conf *conf);
int				valid_conf(char const *str, va_list *arg, int *pft);
int				no_conf(void);
void			ft_print_conf(t_conf *conf, int *pft);
int				print_single_char(char c, int *pft);

int				c_is_symbol(char c);
int				c_is_flag(char c);
int				find_flag(char const *str, char c);
int				check_zero(char const *str);
int				find_c_b(char const *str, char c);
void			delete_1st_char(char *str);
char			get_symb(char const *str_global);
int				ft_find_char(char const *str, char c);
void			set_width(char const *str, t_conf *config);

void			ft_print_d_i(t_conf *conf, int *pft);
void			ft_print_c(t_conf *conf, int *pft);
void			ft_print_s(t_conf *conf, int *pft);
void			ft_print_x(t_conf *conf, int *pft);
void			ft_print_u(t_conf *conf, int *pft);
void			ft_print_p(t_conf *conf, int *pft);
void			ft_print_percentage(t_conf *conf, int *pft);
void			ft_putchar_nb(char c, int nb);
void			ft_putstr_nb(char *str, int nb);

/*
** GET_NEXT_LINE
*/

char			*ft_strcat_char(char *dest, const char *src, char c);
int				ft_strlen_char(const char *str, char c);
char			*ft_strcpy_char(char *dest, char *src, char c);
int				increase_line_size(char **line, int size_sup);
void			update_previous_buffer(char *str);
int				get_next_line(int fd, char **line);

#endif
