#include "push_swap.h"

void 	set_rank(t_list *stk)
{
	int count;
	t_list 	*curr;
	t_data 	**arr;
	int 	outer;
	int 	inner;

	count =ft_lstsize(stk);
	if (count == 0)
		return ;
	arr = malloc(sizeof(t_data *) * count);
	if (!arr)
		return;
	curr = stk;
	outer = 0;
	while (curr)
	{
		arr[outer] = (t_data *)curr->content;
		arr[outer]->rank = 0;
		curr = curr->next;
		outer++;
	}
	outer = 0;
	while (outer < count)
	{
		inner = 0;
		while(inner < count)
		{
			if (arr[outer]->value > arr[inner]->value)
				arr[outer]->rank++;
			inner++;
		}
		outer++;
	}
	free(arr);
}

int max_bits(t_list *stk)
{
	int max_rank;
	t_list 	*curr = stk; 
	int bit_count;

	max_rank = 0;
	while (curr)
	{
		t_data *data = (t_data *)curr->content;
		if (data->rank > max_rank)
			max_rank = data->rank;
		curr = curr->next;
	}
	bit_count = 0;
	while ((max_rank >> bit_count) != 0)
		bit_count++;
	return (bit_count);
}