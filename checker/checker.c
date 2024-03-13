/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:28:03 by omaali            #+#    #+#             */
/*   Updated: 2024/03/12 18:28:07 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
# include "../includes/push_swap.h"
#include <stdbool.h>

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		str_1++;
		str_2++;
	}
	return (*str_1 - *str_2);
}
static void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parcing_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		error(a, b);
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				len;


	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (-1);
	init_stack_a(&a, argv + 1);
	len = ft_lstsize(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parcing_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && len == ft_lstsize(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}