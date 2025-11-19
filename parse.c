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

static  void free_split(char **s)
{
	int i;

	if(!s)
		return ;
	i = 0;
	while(s[i])
		free(s[i++]);
	free(s);
}

static	void add_number(t_stack *a, int nb)
{
	t_node *new;

	new = malloc(sizeof(t_node));
}