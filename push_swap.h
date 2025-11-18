/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:11:22 by dkaymak          #+#    #+#              */
/*   Updated: 2025/11/04 22:11:22 by dkaymak        ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*parse_args(int argc, char **argv);
t_node *node_new(int value);

void	add_back(t_node **stack, int value);

int		list_size(t_node *stack);

void	free_list(t_node **stack);
int		max_bit(t_node *stack);

/* ops.c */
void	sa(t_node **a);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	ra(t_node **a);
void	rra(t_node **a);

/* sort_radix.c */
void	assign_index(t_node *a);
void	radix_sort(t_node **a, t_node **b);

/* sort_small.c */
void	sort_small(t_node **a, t_node **b);

/* utils */
int		is_sorted(t_node *a);

#endif
