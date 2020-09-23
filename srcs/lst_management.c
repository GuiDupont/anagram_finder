#include "../includes/lib.h"

t_word	*put_words_in_lst(int fd)
{
	t_word	*final;
	t_word	*temp;
	char	*line;

	get_next_line(fd, &line);	// this functions has to return the first element of our list
	final = ft_lstnew(line);	// we have to store it somewhere, that's why we use one fist
	temp = final;				// time get_next_line
	free(line);
	while (get_next_line(fd, &line) > 0) // while gnl find content inside the dictionnary
	{
		temp->next = ft_lstnew(line); 	// we want our next pointer to point to the freshly created list element
										// line being exactly a word we can give it to ft_lstnew
		temp = temp->next;				// we jump inside the element recently created, ready to increase the list during
	}									// during the next iteration
	return (final);
}

t_word	*find_anagrams(char *word, t_word *all_words)
{
	t_word	*solutions;
	t_word	*first_elem;
	int		flag_first;

			// same issue here we want to send the first element of our solutions
			// so I used another triks which is to use a 'flag'. This int will let us know
			// if we already created the first element or not.  
	flag_first = 0;
	while (all_words)	// we are going through our linked list of words
	{
		if (ft_is_anagram(word, all_words->content) == 1)	// if they are anagrams we want to add the word to our solution list
		{
			if (flag_first == 0) 	// if it is the first element then we will store it in the pointer firs_elem
			{						// and set the flag to 1;
				solutions = ft_lstnew(all_words->content);
				flag_first = 1;
				first_elem = solutions;
			}
			else					// if it not the first element we can do it normally
			{
				solutions->next = ft_lstnew(all_words->content);
				solutions = solutions->next;
			}
		}
		all_words = all_words->next;
	}
	return (first_elem); 
}
