/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:06:28 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:06:29 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	void	*tmp_content;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp_content = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp_content;
	write(1, "sa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node_to_push;

	if (!a || !*a)
		return ;
	node_to_push = *a;
	*a = node_to_push->next;
	ft_lstadd_front(b, node_to_push);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*node_to_push;

	if (!b || !*b)
		return ;
	node_to_push = *b;
	*b = node_to_push->next;
	ft_lstadd_front(a, node_to_push);
	write(1, "pa\n", 3);
}

void	ra(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
	write(1, "ra\n", 3);
}

void	rra(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rra\n", 4);
}
