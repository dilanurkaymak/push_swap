/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:55:39 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:55:40 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_and_return(char **nums, t_list **head)
{
	ft_free_split(nums);
	free_stack(head);
	return (0);
}

static int	process_number(char *str, t_list **head)
{
	int	value;

	if (!safe_atoi_str(str, &value))
		return (0);
	if (value_exists_in_stack(*head, value))
		return (0);
	append_value(head, value);
	return (1);
}

static int	process_argument(char *arg, t_list **head)
{
	char	**nums;
	int		num_i;

	nums = ft_split(arg, ' ');
	if (!nums)
		return (free_stack(head), 0);
	if (!nums[0])
		return (free_and_return(nums, head));
	num_i = 0;
	while (nums[num_i])
	{
		if (!process_number(nums[num_i], head))
			return (free_and_return(nums, head));
		num_i++;
	}
	ft_free_split(nums);
	return (1);
}

t_list	*parse_args(int argc, char **argv)
{
	int		arg_i;
	t_list	*head;

	head = NULL;
	arg_i = 1;
	while (arg_i < argc)
	{
		if (!process_argument(argv[arg_i], &head))
			return (NULL);
		arg_i++;
	}
	return (head);
}
