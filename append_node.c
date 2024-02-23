/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:14:19 by omaali            #+#    #+#             */
/*   Updated: 2024/02/21 19:23:19 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	append_node(t_stack_node *stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last_node;//to keep track of what we already put
	
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node))
	if (!node)
	{
		free_errors(stack);
		return ;
	}
	node->next = NULL;
	node->nbr = num;// filling the data box of the node with the number
	if (!(*stack))//if it is the first node being put
	{
		stack = node;
		node->prev = NULL;
	}
	else//if there is already nodes
	{
		last_node = find_last(stack);
		last_node->next = node;//we want to put it after the last one present
		node->prev = last_node;
	}
}
