/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:18:18 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/30 23:18:18 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_value(t_stack *stack)
{
	int		min;
	t_node	*node;

	node = stack->top;
	min = node->value;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min;

	while (a->top)
	{
		min = find_min_value(a);
		while (a->top->value != min)
			ra(a, bench);
		pb(a, b, bench);
	}
	while (b->top)
		pa(a, b, bench);
}
