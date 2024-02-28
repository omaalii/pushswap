#include "pushswap.h"

void    swap(t_stack_node *head)
{
    t_stack_node    *first;
    t_stack_node    *second;

    if (ft_lstsize(head) < 2)
        return ;
    first = head;
    second = head->next;
    first->next = second->next;
    second->next = first;
    head = second;
    



}