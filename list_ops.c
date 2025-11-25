#include "push_swap.h"

/* t_data içeren yeni bir t_list düğümü oluşturur */
t_list 	*create_node(int value)
{
	t_data 	*data;
	t_list 	*node;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->value = value;
	data->rank = -1;
	node = ft_lstnew(data);
	if (!node)
	{
		free(data);
		return (NULL);
	}
	return (node);
}

/* Yığına (stk) yeni bir değer ekler */
void 	append_value(t_list **stk, int value)
{
	t_list *node = create_node(value);
	if (!node)
	{
		/* bellekte yer yoksa çağırana bırak */
		return ;
	}
	ft_lstadd_back(stk, node);
}

/* Yığını (stk) ve içindeki t_data içeriklerini temizler */
void 	free_stack(t_list **stk)
{
	if (!stk)
		return ;
	ft_lstclear(stk, free);
}