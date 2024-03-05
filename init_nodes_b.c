#include "pushswap.h"

void    set_target_b()

void    init_nodes_b(t_stack_node **a, t_stack_node **b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}