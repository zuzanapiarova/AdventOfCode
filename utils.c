#include "aoc.h"

int	ft_lstsize(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_lst	*ft_lstnew(int value)
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

void	ft_lstadd_back(t_lst **head, t_lst *new_node)
{
	t_lst	*temp;

	if (!new_node)
		return ;
	if (!head || !*head)  // Check if the head pointer or the list is empty
	{
		*head = new_node; // Set the new node as the head
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void lst_free(t_lst **head)
{
    t_lst *temp;
    t_lst *rem;

    if (!head || !*head)
        return ;
    temp = *head;
    while(temp)
    {
        rem = temp;
        temp = temp->next;
        free(rem);
    }
    *head = NULL;
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


static int	words_len(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strndub(char *src, int n)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < n)
	{
		res[i] = src[i];
		i += 1;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_len;
	char	**split;
	int		current_word;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (words_len((char *)s, c) + 1));
	if (!split)
		return (NULL);
	current_word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		word_len = i;
		if (word_len > 0)
			split[current_word++] = ft_strndub((char *)s, word_len);
		s += word_len;
	}
	split[current_word] = NULL;
	return (split);
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
