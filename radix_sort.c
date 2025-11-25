#include "push_swap.h"

void 	radix_sort(t_list **stk_a, t_list **stk_b)
{
	int bit;
	int loop;
	int size;
	int limit;

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
			t_data *head = (t_data *)(*stk_a)->content;
			// Current bit 1 ise ra yap, 0 ise pb yap
			if (((head->rank >> bit) & 1) == 1) 
				ra(stk_a);
			else
				pb(stk_a, stk_b);
			loop++;
		}
		// B'deki tüm elemanları A'ya geri al
		while (*stk_b)
			pa(stk_a, stk_b);
		bit++;
	}
}