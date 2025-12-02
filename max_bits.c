/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:36:46 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:36:47 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_list *stk)
{
	int		max_rank;
	t_list	*curr;
	t_data	*data;
	int		bit_count;

	max_rank = 0;
	curr = stk;
	while (curr)
	{
		data = (t_data *)curr->content;
		if (data->rank > max_rank)
			max_rank = data->rank;
		curr = curr->next;
	}
	bit_count = 0;
	while ((max_rank >> bit_count) != 0)
		bit_count++;
	return (bit_count);
}
