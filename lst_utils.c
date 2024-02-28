#include "pushswap.h"

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
