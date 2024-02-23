/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:02:31 by omaali            #+#    #+#             */
/*   Updated: 2024/02/21 19:23:09 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack_a(t_stack_node *a, char **argv)
{
	long	num;
	int		index;

	index = 0;
	while (argv[index])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		num = ft_atol(argv[i])
		if (num > INT_MAX || num < INT_MIN)
			free_errors(a);
		if (errors_duplicate(a, (int)num))
			free_errors(a);
		append_node(a, (int)num);
		index++;
	}
}
