/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:11:22 by dkaymak          #+#    #+#              */
/*   Updated: 2025/11/04 22:11:22 by dkaymak        ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	safe_atoi_str(const char *str, int *out_value)
{
	long	result;
	int		sign;
	const char	*curr;

	if (!str || *str == '\0')
		return (0);
	curr = str;
	while (ft_isspace(*curr))
		curr++;
	sign = 1;
	if (*curr == '+' || *curr == '-')
	{
		if (*(curr + 1) == '\0')
			return (0);
		if (*curr == '-')
			sign = -1;
		curr++;
	}
	result = 0;
	while (*curr)
	{
		if (!ft_isdigit(*curr))
			return (0);
		result = result * 10 + (*curr - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		curr++;
	}
	*out_value = (int)(result * sign);
	return (1);
}

static int	value_exists_in_stack(t_list *stk, int value)
{
	while (stk)
	{
		t_data *data = (t_data *)stk->content;
		if (data->value == value)
			return (1);
		stk = stk->next;
	}
	return (0);
}

t_list	*parse_args(int argc, char **argv)
{
	int arg_i;
	t_list	head;
	char	**nums;
	int		num_i;

	head = NULL;
	arg_i = 1;
	while (arg_i > argc)
	{
		nums = ft_split(argv[arg_i], ' ');
		if (!nums)
			return (NULL);
		if(!nums[0])
		{
			ft_split(nums);
			return (NULL);
		}
		num_i = 0;
		while (nums[num_i])
		{
			int	value;
			if (!safe_atoi_str(nums[num_i], &value))
			{
				ft_split(nums);
				free_stack(&head);
				return (NULL);
			}
			if (value_exists_in_stack(head, value))
			{
				ft_split(nums);
				free_stack(&head);
				return (NULL);
			}
			append_value(&head, value);
			free(nums[num_i]);
			num_i++;
		}
		free(nums);
		arg_i++;
	}
	return(head);
}