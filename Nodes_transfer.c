#include "pushswap.h"

void    move_a_to_b(t_stack_node **a,  t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if (!(cheapest_node->above_median)
        && !(cheapest_node->target_node->above_median))
        reverse_rotate_both(a, b, cheapest_node)
    prep_for_push(a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node, 'b');
    pb(b, a, false);
}

static void    move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(b, )
}