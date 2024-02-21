/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:02:31 by omaali            #+#    #+#             */
/*   Updated: 2024/02/21 19:11:48 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_stack_a(t_stack_node *a, char **argv)
{
	long	value;
	int		index;

	index = 0;
	while (argv[index])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		value = ft_atol(argv[i])
		if (value > INT_MAX || value < INT_MIN)
			free_errors(a);
		if (errors_duplicate(a, (int)value))
			free_errors(a);
		append_node(a, (int)value);
		index++;
	}
}
