/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:25:54 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:25:55 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bit_ctrl(t_list **stk_a, t_list **stk_b, int bit)
{
	t_data	*head;

	head = (t_data *)(*stk_a)->content;
	if (((head->rank >> bit) & 1) == 1)
		ra(stk_a);
	else
		pb(stk_a, stk_b);
}

void	radix_sort(t_list **stk_a, t_list **stk_b)
{
	int	bit;
	int	loop;
	int	size;
	int	limit;

	if (!stk_a || !*stk_a)
		return ;
	limit = max_bits(*stk_a);
	bit = 0;
	while (bit < limit)
	{
		size = ft_lstsize(*stk_a);
		loop = 0;
		while (loop < size)
		{
			bit_ctrl(stk_a, stk_b, bit);
			loop++;
		}
		while (*stk_b)
			pa(stk_a, stk_b);
		bit++;
	}
}
