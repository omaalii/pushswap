#include "pushswap.h"

void sort_three(t_stack_node **stack)
{
    t_Stack_node *biggest_node;

    biggest_node = find_max(*a);
    if (biggest_node == *a)
        ra(a, false);
    else if ((*a)->next == biggest_node)
        rra(*a, false);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);
}