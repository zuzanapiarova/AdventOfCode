#ifndef AOC_H
# define AOC_H
#include <stdio.h>
#include <libc.h>
#include "aoc.h"

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
	int			    done;
}					t_lst;

/* utils.c */
int     ft_lstsize(t_lst *lst);
t_lst	*ft_lstnew(int value);
void    ft_lstadd_back(t_lst **head, t_lst *new_node);
void    lst_free(t_lst **head);

#endif
