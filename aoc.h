#ifndef AOC_H
# define AOC_H
#include <stdio.h>
#include <libc.h>
#include <stdlib.h>
#include "aoc.h"
#include "libft/libft.h"

// compile with cc -o my_project challenges/four.c utils.c -L./libft -lft -I./libft

#define MAX_LINES 200
#define MAX_LINE_LENGTH 1024

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
	int			    done;
}					t_lst;

/* utils.c */
t_lst	*ft_lstnew_int(int value);
int	get_arr_size(char **arr);
void free_arr(char **arr);

#endif
