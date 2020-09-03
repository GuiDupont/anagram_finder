# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#include "get_next_line.h"

typedef struct Element Element;
struct Element
{
    char *word;
    Element *next;
};

typedef struct List List;
struct List
{
    Element *first;
};

List *initialisation()
{
    List       *list = malloc(sizeof(*list));
    Element    *element = malloc(sizeof(*element));
    
    if (!(list = (List *)malloc(sizeof(List))))
        return (NULL);
    
    element->word = 0;
    element->next = NULL;
    list->first = element;
    
    return (list);
}

void    insertion(List *list, char *newWord)
{
    Element *new;
    
    if (!list || !new)
        return ;
    new = malloc(sizeof(*new));
    
    new->word = newWord;
    // printf("%s\n", new->word);
    new->next = list->first;
    list->first = new;
}

void display_lst(List *list)
{
    if (!list)
        return ;
    
    Element *actual = list->first;

    while (!actual)
    {
        printf("%s -> ", actual->word);
        actual = actual->next;
    }
}

int main(int argc, char **argv)
{
    List *dico;
    int fd;
    char *line;

    dico = initialisation();
    if (argc != 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        insertion(dico, line);
    }
    display_lst(dico);
    return (0);
}
