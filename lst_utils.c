#include "push_swap.h"

int ft_lstsize(t_stack_node *lst)
{
    int size;

    size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}
t_stack_node	*find_last(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void    ft_prev_put(t_stack_node **head)
{
    t_stack_node    *current_node;
    t_stack_node    *prev_node

    prev_node = NULL;
    current_node = *head;
    while (current_node)
    {
        current_node->prev = prev_node;
        prev_node = current_node;
        current_node = current_node->next;
    }
}
