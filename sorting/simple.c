/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/07 13:47:42 by username         #+#    #+#              */
/*   Updated: 2026/09/07 13:47:42 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+
+:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+
+#+         */
/*                                               +#+#+#+#+#+
+#+            */
/*   Created: 2026/08/30 23:18:18 by username         #+#    #+#              */
/*   Updated: 2026/09/07 13:46:19 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *a)
{
	t_node	*node;
	int		min;
	int		min_pos;
	int		pos;

	node = a->top;
	min = node->value;
	min_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min_pos;

	if (a->size <= 3)
	{
		small_sort(a, bench);
		return ;
	}
	while (a->top)
	{
		min_pos = find_min_position(a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				ra(a, bench);
		}
		else
		{
			min_pos = a->size - min_pos;
			while (min_pos-- > 0)
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (b->top)
		pa(a, b, bench);
}
