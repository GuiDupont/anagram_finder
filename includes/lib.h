#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

# define PARTIAL_ACCEPTED 1
# define PARTIAL_NOT_ACCEPTED 0

typedef	struct	s_word
{
	char			*word;
	int				len;
	char			*nature;
	struct s_word	*next;
}				t_word;


/* for now we can use t_list structs for our program. By using a 
** typedef we can say that writting "t_word" = writing "t_list" and then 
** use all t_list functions.
*/

typedef struct s_global
{
	char	*main_sentence;
	t_word	*dico;
	t_word	*solutions;
	t_word	*partial_solutions;
}			t_global;

t_word	*put_words_in_lst(int fd);
t_word	*find_anagrams(char *word, t_word *all_words, int partial_anagrams);

int		ft_is_anagram(char *word, char *candidate, int partial_accepted);

void	ft_print_lst(t_word *lst, char *str);
t_word	*ft_lst_word_new(void *content, int len);
void	ft_lstdel(t_word **lst);

#endif
