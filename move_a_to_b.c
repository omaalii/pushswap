#include "pushswap.h"

void    move_a_to_b(t_stack_node **a,  t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if ()
}