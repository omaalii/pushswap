#include "pushswap.h"

void    swap(t_stack_node **head)
{
    t_stack_node    *first;
    t_stack_node    *second;

    if (ft_lstsize(*head) < 2)
        return ;
    first = *head;
    second = (*head)->next;
    first->next = second->next;//removes second node
    second->next = first;//puts second node before the first
    *head = second;//update the head* to set "second" as the head of stack
    ft_prev_put(head);//resets the prevs links of nodes in the stack
}

void    sa(t_stack_node **a, bool print)
{
    swap(a);
    if (!print)
        write(1, "sa\n", 3);
}

void    sb(t_stack_node **b, bool print)
{
    swap(b);
    if (!print)
        write(1, "sb\n", 3);
}

void    ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if (!print)
        write(1, "ss\n", 3);
}