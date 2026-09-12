/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 08:08:13 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 08:08:13 by jsingh           ###   ########.fr       */
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

static void	move_min_to_top(t_stack *a, t_bench *bench)
{
	int	min_pos;

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
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size <= 3)
	{
		small_sort(a, bench);
		return ;
	}
	if (a->size <= 5)
	{
		sort_five(a, b, bench);
		return ;
	}
	while (a->top)
	{
		move_min_to_top(a, bench);
		pb(a, b, bench);
	}
	while (b->top)
		pa(a, b, bench);
}
