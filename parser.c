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

static  void fee_split(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		free(arr[i++]);
	free(arr);
}

static	void add_number(t_stack *a, int nb)
{
	

	new = malloc(sizeof(t_node));
}