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
