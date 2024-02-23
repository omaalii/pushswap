/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:39:21 by omaali            #+#    #+#             */
/*   Updated: 2024/02/21 18:54:58 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#	include <stdbool.h>
#	include <limits.h>
#	include "pushswap.h"

typedef	struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;
	
	//Handle errors
	//Stack initiation 
	//Nodes initiation
	//Stack utils
	//Commands 
	//Algorithms

#endif
