#include "aoc.h"

t_lst	*ft_lstnew_int(int value)
{
	t_lst	*result;

	result = (t_lst *)malloc(sizeof(t_lst));
	if (!result)
		return (NULL);
	result->value = value;
    result->done = 0;
	result->next = NULL;
	return (result);
}

int	get_arr_size(char **arr)
{
	int		i;

	if (!arr || !(*arr))
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void free_arr(char **arr)
{
    int i = 0;

    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    arr = NULL;
}
