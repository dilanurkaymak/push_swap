/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:05:40 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:05:41 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_data	*data;
	t_list	*node;

	data = (t_data *)malloc(sizeof(t_data));
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

void	append_value(t_list **stk, int value)
{
	t_list	*node;

	node = create_node(value);
	if (!node)
	{
		return ;
	}
	ft_lstadd_back(stk, node);
}

void	free_stack(t_list **stk)
{
	if (!stk)
		return ;
	ft_lstclear(stk, free);
}
