#ifndef ANAGRAM_H
# define ANAGRAM_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

# define PARTIAL_ACCEPTED 1
# define PARTIAL_NOT_ACCEPTED 0

# define NOUN 0
# define ADJ 1
# define ADV 2
# define ABBR 3
# define CONJ 4
# define VAR 5
# define PREP 6
# define PRON 7
# define VERB 8
# define NATURE_NB 9

typedef	struct	s_word
{
	char			*word;
	int				len;
	char			*nature;
	struct s_word	*next;
}				t_word;

typedef struct s_global
{
	t_word	*dico;
	t_word	*partial_solutions_by_nature[10];
	t_word	*solutions;
	t_word	*partial_solutions;
}			t_global;

t_word	*put_words_in_lst(int fd);
t_word	*find_anagrams(char *word, t_word *all_words, int partial_anagrams);

int		ft_is_anagram(char *word, char *candidate, int partial_accepted);

void	ft_print_lst(t_word *lst, char *str);
t_word	*ft_lst_word_new(void *content, int len, char *nature);
void	ft_lstdel(t_word **lst, int free_inside);
int		ft_lstsize(t_word *lst);
void	clean_dico_from_composed_word(t_word *dico);
void	lst_to_nature_ordered(t_word *lst, t_word *ordered[10]);
void	ft_del_partial_solution_by_nature(t_word **lst);

#endif
