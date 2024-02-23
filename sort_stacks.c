#include "pushswap.h"

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;

    len_a = stack_len(*a);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb (*b, *a, false);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb (*b, *a, false);
    while (len_a-- > 3 && !stack_sorted(*a))
    {
        init_nodes_a(*a, *b);
    }
}