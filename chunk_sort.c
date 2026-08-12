/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:36:06 by username          #+#    #+#             */
/*   Updated: 2026/08/12 16:23:34 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_node	*node;
	t_node	*i;
	int		index;

	node = stack->top;
	while (node)
	{
		index = 0;
		i = stack->top;
		while (i)
		{
			if (i->value < node->value)
				index++;
			i = i->next;
		}
		node->index = index;
		node = node->next;
	}
}

int	get_chunk_size(t_stack *stack)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < stack->size)
		chunk_size++;
	return (chunk_size);
}

int	find_max_position(t_stack *stack)
{
	int		max;
	int		max_pos;
	int		pos;
	t_node	*i;

	pos = 0;
	max_pos = 0;
	if (!stack || !stack->top)
		return (-1);
	i = stack->top;
	max = i->index;
	while (i)
	{
		if (i->index > max)
		{
			max = i->index;
			max_pos = pos;
		}
		pos++;
		i = i->next;
	}
	return (max_pos);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_end;
	int	max_pos;

	assign_index(a);
	chunk_size = get_chunk_size(a);
	chunk_end = chunk_size;
	while (a->top)
	{
		if (a->top->index < chunk_end)
		{
			pb(a, b);
			if (b->size == chunk_end)
				chunk_end += chunk_size;
		}
		else
			ra(a);
	}
	while (b->top)
	{
		max_pos = find_max_position(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = b->size - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}
