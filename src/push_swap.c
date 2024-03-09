/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:59:37 by omaali            #+#    #+#             */
/*   Updated: 2024/03/09 18:30:08 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	printstack(t_stack_node **st)
{
	t_stack_node *tmp;
	int i;

	if (*st)
		return ;
	i = 0;
	tmp = *st;
	while (tmp)
	{
		printf("HERE\n");	
		printf("num -----[%i] --- %d\n", i, tmp->nbr);
		i++;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (-1);
	init_stack_a(&a, argv + 1);
	printstack(&a);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
