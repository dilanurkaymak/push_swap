/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:47:13 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 16:48:43 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	**ft_prepare_arr(t_list *stk, int count)
{
	t_data	**arr;
	t_list	*curr;
	int		i;

	arr = (t_data **)malloc(sizeof(t_data *) * count);
	if (!arr)
		return (NULL);
	curr = stk;
	i = 0;
	while (curr)
	{
		arr[i] = (t_data *)curr->content;
		arr[i]->rank = 0;
		curr = curr->next;
		i++;
	}
	return (arr);
}

void	ft_calculate_ranks(t_data **arr, int count)
{
	int	outer;
	int	inner;

	outer = 0;
	while (outer < count)
	{
		inner = 0;
		while (inner < count)
		{
			if (arr[outer]->value > arr[inner]->value)
				arr[outer]->rank++;
			inner++;
		}
		outer++;
	}
}

void	set_rank(t_list *stk)
{
	int		count;
	t_data	**arr;

	count = ft_lstsize(stk);
	if (count == 0)
		return ;
	arr = ft_prepare_arr(stk, count);
	if (!arr)
		return ;
	ft_calculate_ranks(arr, count);
	free(arr);
}
