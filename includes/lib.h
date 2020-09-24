#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef t_list t_word;

/* for now we can use t_list structs for our program. By using a 
** typedef we can say that writting "t_word" = writing "t_list" and then 
** use all t_list functions.
*/
t_word	*put_words_in_lst(int fd);
t_word	*find_anagrams(char *word, t_word *all_words);
t_word	*find_partial_anagrams(char *word, t_word *all_words);

int		ft_is_anagram(char *word, char *candidate, int partial_accepted);

void	ft_print_lst(t_word *lst, char *str);

void	print_partial_solutions(t_word *partial_solutions);

#endif