#include "push_swap.h"

static void sort_two(t_list **stk)
{
	t_data	*top_node;
	t_data	*mid_node;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	top_node = (*stk)->content;
	mid_node = (*stk)->next->content;
	if (top_node->value > mid_node->value)
		sa(stk);
}

static void sort_three(t_list **stk)
{
	t_data	*top_node;
	t_data	*mid_node;
	t_data	*bot_node;

	if (!stk || !*stk || ft_lstsize(*stk) < 3)
		return ;
	top_node = (*stk)->content;
	mid_node = (*stk)->next->content;
	bot_node = (*stk)->next->next->content;
	if (top_node->value > mid_node->value && mid_node->value < bot_node->value && top_node->value < bot_node->value)
		sa(stk);
	else if (top_node->value > mid_node->value && mid_node->value > bot_node->value)
	{
		sa(stk);
		rra(stk);
	}
	else if (top_node->value > mid_node->value && mid_node->value < bot_node->value && top_node->value > bot_node->value)
		ra(stk);
	else if (top_node->value < mid_node->value && mid_node->value > bot_node->value && top_node->value < bot_node->value)
	{
		sa(stk);
		ra(stk);
	}
	else if (top_node->value < mid_node->value && mid_node->value > bot_node->value && top_node->value > bot_node->value)
		rra(stk);
}

static int get_min_pos(t_list *stk)
{
	t_data	*node;
	int		min_val;
	int		min_pos;
	int		i;

	if (!stk)
		return (-1);
	node = stk->content;
	min_val = node->value;
	min_pos = 0;
	i = 0;
	while (stk)
	{
		node = stk->content;
		if (node->value < min_val)
		{
			min_val = node->value;
			min_pos = i;
		}
		stk = stk->next;
		i++;
	}
	return (min_pos);
}

static void push_min_to_b(t_list **a, t_list **b)
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
void sort_small(t_list **stk_a, t_list **stk_b)
{
	int	size;

	size = ft_lstsize(*stk_a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		sort_two(stk_a);
		return ;
	}
	if (size == 3)
	{
		sort_three(stk_a);
		return ;
	}
	while (size > 3)
	{
		push_min_to_b(stk_a, stk_b);
		size--;
	}
	sort_three(stk_a);
	while (*stk_b)
	{
		pa(stk_a, stk_b);
		ra(stk_a);
	}
}
