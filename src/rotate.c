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
	t_stack_node	*temp;

	head = *stack;
	temp = *stack;
	if (!(*stack) || !(*stack)->next)
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
	t_stack_node	*temp;

	if (*stack == NULL || !(*stack)->next)
		return ;
	current = *stack;
	head = *stack;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = head;
	*stack = temp;
	ft_prev_put(stack);
}
