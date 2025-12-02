/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:36:15 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:36:16 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_list *stk)
{
	t_data	*node;
	int		min_val;
	int		min_pos;
	int		i;

	if (!stk)
		return (-1);
	node = (t_data *)stk->content;
	min_val = node->value;
	min_pos = 0;
	i = 0;
	while (stk)
	{
		node = (t_data *)stk->content;
		if (node && node->value < min_val)
		{
			min_val = node->value;
			min_pos = i;
		}
		stk = stk->next;
		i++;
	}
	return (min_pos);
}

static void	sort_two(t_list **stk)
{
	t_data	*top_node;
	t_data	*mid_node;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	top_node = (t_data *)(*stk)->content;
	mid_node = (t_data *)(*stk)->next->content;
	if (top_node->value > mid_node->value)
		sa(stk);
}

static void	sort_three(t_list **stk)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(*stk))
		return ;
	top = ((t_data *)(*stk)->content)->value;
	mid = ((t_data *)(*stk)->next->content)->value;
	bot = ((t_data *)(*stk)->next->next->content)->value;
	if (top > mid && mid < bot && top < bot)
		sa(stk);
	else if (top > mid && mid > bot)
	{
		sa(stk);
		rra(stk);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stk);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stk);
		ra(stk);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stk);
}

static void	push_min_to_b(t_list **a, t_list **b)
{
	int	size;
	int	min_pos;
	int	moves;

	size = ft_lstsize(*a);
	min_pos = get_min_pos(*a);
	if (min_pos > size / 2)
	{
		moves = size - min_pos;
		while (moves-- > 0)
			rra(a);
	}
	else
	{
		moves = min_pos;
		while (moves-- > 0)
			ra(a);
	}
	pb(a, b);
}

void	sort_small(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		sort_two(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (ft_lstsize(*a) > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
