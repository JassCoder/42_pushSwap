/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:18:00 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/30 23:18:00 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(t_stack *stack)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < stack->size)
		chunk_size++;
	return (chunk_size);
}

static int	find_max_position(t_stack *stack)
{
	int		max;
	int		max_pos;
	int		pos;
	t_node	*node;

	if (!stack || !stack->top)
		return (-1);
	pos = 0;
	max_pos = 0;
	node = stack->top;
	max = node->index;
	while (node)
	{
		if (node->index > max)
		{
			max = node->index;
			max_pos = pos;
		}
		pos++;
		node = node->next;
	}
	return (max_pos);
}

static void	push_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk_size;
	int	chunk_end;

	chunk_size = get_chunk_size(a);
	chunk_end = chunk_size;
	while (a->top)
	{
		if (a->top->index < chunk_end)
		{
			pb(a, b, bench);
			if (b->size == chunk_end)
				chunk_end += chunk_size;
		}
		else
			ra(a, bench);
	}
}

static void	push_back(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_pos;

	while (b->top)
	{
		max_pos = find_max_position(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				rb(b, bench);
		}
		else
		{
			max_pos = b->size - max_pos;
			while (max_pos-- > 0)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	assign_index(a);
	push_chunks(a, b, bench);
	push_back(a, b, bench);
}
