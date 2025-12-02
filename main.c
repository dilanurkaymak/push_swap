/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:31:12 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 16:31:23 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stk)
{
	t_data	*cur;
	t_data	*next;

	while (stk && stk->next)
	{
		cur = (t_data *)stk->content;
		next = (t_data *)stk->next->content;
		if (cur->value > next->value)
			return (0);
		stk = stk->next;
	}
	return (1);
}

static t_list	*handle_parsing(int argc, char **argv)
{
	t_list	*stk_a;

	stk_a = NULL;
	if (argc < 2)
		return (NULL);
	stk_a = parse_args(argc, argv);
	if (!stk_a)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stk_a);
}

static void	run_sort_logic(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 7)
		sort_small(a, b);
	else
	{
		set_rank(*a);
		radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	stk_b = NULL;
	stk_a = handle_parsing(argc, argv);
	if (!stk_a)
		return (1);
	if (!is_sorted(stk_a))
		run_sort_logic(&stk_a, &stk_b);
	free_stack(&stk_a);
	free_stack(&stk_b);
	return (0);
}
