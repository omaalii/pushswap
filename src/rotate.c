/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:05:29 by omaali            #+#    #+#             */
/*   Updated: 2024/03/08 08:05:31 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*head;
	t_stack_node	*temp;//temporary head address to reasign to the new head node

	head = *stack;
	temp = *stack;
	if (!(*stack)->next)
		return ;
	temp = temp->next;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = head;
	head->next = NULL;
	*stack = temp;
	ft_prev_put(stack);
}

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*head;
	t_stack_node	*temp;//temporary head address to reasign to the new head node

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

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}

void	rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}