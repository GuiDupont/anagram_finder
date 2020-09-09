#ifndef LIB_H
# define LIB_H

typedef struct s_list
{
    char            *word;
    struct s_list   *next;
}                   t_list;
