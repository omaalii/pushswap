/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:06:05 by omaali            #+#    #+#             */
/*   Updated: 2024/03/08 08:06:07 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_stack_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack_node	*find_last(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_prev_put(t_stack_node **head)
{
	t_stack_node	*current_node;
	t_stack_node	*prev_node;

	prev_node = NULL;
	current_node = *head;
	while (current_node)
	{
		current_node->prev = prev_node;
		prev_node = current_node;
		current_node = current_node->next;
	}
}

int	ft_isdigit(char c)
{
	if (c <= '0' && c >= '9')
		return (1);
	return (0);
}
