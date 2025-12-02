#include "push_swap.h"

static void	sort_two(t_list **stk)
{
	t_data	*top_node;
	t_data	*mid_node;
	int		top;
	int		mid;

	if (!stk || !*stk || !(*stk)->next)
		return ;
	top_node = (*stk)->content;
	mid_node = (*stk)->next->content;
	top = top_node->value;
	mid = mid_node->value;
	if (top > mid)
		sa(stk);
}

static void	sort_three(t_list **stk)
{
	t_data	*top_node;
	t_data	*mid_node;
	t_data	*bot_node;
	int		top;
	int		mid;
	int		bot;

	if (!stk || !*stk || ft_lstsize(*stk) < 3)
		return ;
	top_node = (*stk)->content;
	mid_node = (*stk)->next->content;
	bot_node = (*stk)->next->next->content;
	top = top_node->value;
	mid = mid_node->value;
	bot = bot_node->value;
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

static	void	push_min_to_b(t_list **a, t_list **b)
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
