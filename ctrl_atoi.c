/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:53:41 by dkaymak           #+#    #+#             */
/*   Updated: 2025/12/02 17:53:42 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	skip_whitespace(const char **str)
{
	while (**str && (**str == ' ' || **str == '\t' || **str == '\n'
			|| **str == '\r' || **str == '\f' || **str == '\v'))
		(*str)++;
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	safe_atoi_core(const char **str, long *result)
{
	while (**str && ft_isdigit(**str))
	{
		if (*result > (long)INT_MAX / 10 || 
			(*result == (long)INT_MAX / 10 && (**str - '0') > INT_MAX % 10))
			return (0);
		*result = *result * 10 + (**str - '0');
		(*str)++;
	}
	return (1);
}

int	safe_atoi_str(const char *str, int *out_value)
{
	long	result;
	int		sign;
	const char *start;

	result = 0;
	if (!str || *str == '\0')
		return (0);
	skip_whitespace(&str);
	if (*str == '\0')
		return (0);
	sign = get_sign(&str);
	start = str;
	if (*str == '\0' || !ft_isdigit(*str))
		return (0);
	if (!safe_atoi_core(&str, &result))
		return (0);
	if (*str != '\0' || str == start)
		return (0);
	if (sign == -1 && result > (long)INT_MAX + 1)
		return (0);
	*out_value = (int)(result * sign);
	return (1);
}
