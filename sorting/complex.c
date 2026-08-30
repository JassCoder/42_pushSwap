/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:19:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/30 23:19:41 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *stack)
{
	int		max;
	t_node	*node;

	node = stack->top;
	max = node->index;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

static int	get_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	assign_index(a);
	size = a->size;
	max_bits = get_max_bits(get_max_index(a));
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			i++;
		}
		while (b->top)
			pa(a, b, bench);
		bit++;
	}
}
