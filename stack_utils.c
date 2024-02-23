bool    stack_sorted(t_stack_node *stack)
{
    if(!stack)
        return (NULL);
    while (stack->next)
    {
        if (stac->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}





