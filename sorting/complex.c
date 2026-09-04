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

static int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void process_a(t_stack *a, t_stack *b, t_bench *bench, int bit)
{
	int i;
	int size;

	i = 0;
		size = a->size;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			i++;
		}
}

static void	process_b(t_stack *a, t_stack *b, t_bench *bench, int bit, int max_bits)
{
	int	i;
	int b_size;

	i = 0;
	b_size = b->size;
	if (bit + 1 < max_bits)
		{
			b_size = b->size;
			i = 0;
			while (i < b_size)
			{
				if (((b->top->index >> (bit + 1)) & 1) == 1)
					pa(a, b, bench);
				else
					rb(b, bench);
				i++;
			}
		}
		else
		{ 
			while (b->top)
				pa(a,b,bench);
		}
}

void	complex_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_bits;
	int	bit;

	assign_index(a);
	max_bits = get_max_bits(a->size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		process_a(a, b, bench, bit);
		process_b(a, b, bench, bit, max_bits);
		bit++;
	}
}
