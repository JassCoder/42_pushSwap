/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:56:48 by username          #+#    #+#             */
/*   Updated: 2026/09/12 01:51:17 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (first > second && first > third)
		ra(a, bench);
	else if (second > first && second > third)
		rra(a, bench);
	if (a->top->value > a->top->next->value)
		sa(a, bench);
}

void	small_sort(t_stack *a, t_bench *bench)
{
	if (a->size == 2)
		sa(a, bench);
	if (a->size == 3)
		sort3(a, bench);
}

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

void	sort_five(t_stack *a, t_stack *b, t_bench *bench)
{
	while (a->size > 3)
	{
		move_min_to_top(a, bench);
		pb(a, b, bench);
	}
	small_sort(a, bench);
	while (b->top)
		pa(a, b, bench);
}
