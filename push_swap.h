#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_data
{
	int				value;
	int				rank;
}	t_data;

t_list	*parse_args(int argc, char **argv);

t_list	*create_node(int value);
void	append_value(t_list **stk, int value);
void	free_stack(t_list **stk);

void	sa(t_list **stk);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ra(t_list **stk);
void	rra(t_list **stk);

void	set_rank(t_list *stk);
int		max_bits(t_list *stk);
void	radix_sort(t_list **stk_a, t_list **stk_b);

void	sort_small(t_list **stk_a, t_list **stk_b);

#endif
