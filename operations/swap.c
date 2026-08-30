/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:13:35 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/26 20:13:35 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_raw(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	return (1);
}

void	sa(t_stack *a, t_bench *bench)
{
	if (swap_raw(a))
	{
		write(1, "sa\n", 3);
		bench->sa++;
		bench->total++;
	}
}

void	sb(t_stack *b, t_bench *bench)
{
	if (swap_raw(b))
	{
		write(1, "sb\n", 3);
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_stack	*a, t_stack *b, t_bench *bench)
{
	int	changed;

	changed = 0;
	if (swap_raw(a))
		changed = 1;
	if (swap_raw(b))
		changed = 1;
	if (changed)
	{
		write(1, "ss\n", 3);
		bench->ss++;
		bench->total++;
	}
}
