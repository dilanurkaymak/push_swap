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

typedef struct s_data
{
	int				value;
	int				index;
}	t_data;

t_list	*parse_args(int argc, char **argv);

int		is_sorted(t_list *stack);
int		has_duplicates(int *arr, int size);
int		get_max_bits(t_list *stack);

void	sa(t_list **a);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);

void	sort_small(t_list **a, t_list **b);

void	assign_index(t_list *a);
void	radix_sort(t_list **a, t_list **b);

#endif
