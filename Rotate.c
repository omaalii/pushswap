#include "pushswap.h"

void    rotate(t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *head;
    t_stack_node    *temp;//temporary head address to reasign to the new head node

    head = *stack;
    temp = *stack;
    temp = temp->next;
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = head;
    head->next = NULL;
    *stack = temp;
    ft_prev_put(stack);
}

void    reverse_rotate(t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *head;
    t_stack_node    *temp;//temporary head address to reasign to the new head node

    current = *stack;
    head = *stack;
    while (current->next->next)//current reaches the second to last node
        current = current->next;
    temp = current->next;//temp becomes the last node
    current->next = NULL;//we free the last node from the stack
    temp->next = head;//making the former last node the head of the stack
    *stack = temp;//updating the stack head to the new top node
    ft_prev_put(stack);
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        write(1, "ra\n", 3)
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        write(1, "rb\n", 3)
}

void    rra(t_stack_node **a, bool print)
{
    reverse_rotate(a);
    if(!print)
        write(1, "rra\n", 4)
}

void    rrb(t_stack_node **b, bool print)
{
    reverse_rotate(b);
    if(!print)
        write(1, "rrb\n", 4)
}

