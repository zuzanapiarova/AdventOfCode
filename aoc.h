#include <stdio.h>
#include <libc.h>

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
	int				i;
}					t_lst;
