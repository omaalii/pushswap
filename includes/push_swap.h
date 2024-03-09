/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:39:21 by omaali            #+#    #+#             */
/*   Updated: 2024/03/08 16:44:44 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

	//Handle errors
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
int				error_syntax(char *str_nbr);
int				errors_duplicate(t_stack_node *a, int num);
//Stack initiation 
void			init_stack_a(t_stack_node **a, char **argv);
// long		ft_atol(const char *s);
void			append_node(t_stack_node *stack, int num);
//Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
//Stack utils
int				ft_isdigit(char c);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *top_node,
					char stack_name);
void			current_index(t_stack_node *stack);
void			cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
int				ft_lstsize(t_stack_node *lst);
t_stack_node	*find_last(t_stack_node *lst);
void			ft_prev_put(t_stack_node **head);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
//Commands 
void			swap(t_stack_node **head);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			rotate(t_stack_node **stack);
void			reverse_rotate(t_stack_node **stack);
void			rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
//Algorithms
void			sort_three(t_stack_node **stack);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			min_on_top(t_stack_node **a);

#endif
