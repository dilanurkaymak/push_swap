/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:19:46 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:19:47 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	value_exists_in_stack(t_list *stk, int value)
{
	t_data	*data;

	while (stk)
	{
		data = (t_data *)stk->content;
		if (data->value == value)
			return (1);
		stk = stk->next;
	}
	return (0);
}
