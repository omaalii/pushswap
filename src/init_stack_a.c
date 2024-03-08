/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:02:31 by omaali            #+#    #+#             */
/*   Updated: 2024/03/08 11:07:34 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_node(t_stack_node *stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
	{
		free_errors(&stack);
		return ;
	}
	node->next = NULL;
	node->nbr = num;
	if (!(stack))
	{
		stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
		*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	num;
	int		index;

	index = 0;
	while (argv[index])
	{
		if (error_syntax(argv[index]))
			free_errors(a);
		num = ft_atol(argv[index]);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(a);
		if (errors_duplicate(*a, (int)num))
			free_errors(a);
		append_node(*a, (int)num);
		index++;
	}
}
