/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 23:08:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/26 23:08:41 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	push_raw(t_stack *from, t_stack *to)
{
	t_node	*moved;

	if (from->size == 0)
		return (0);
	moved = from->top;
	from->top = from->top->next;
	from->size--;
	if (from->size == 0)
		from->bottom = NULL;
	moved->next = to->top;
	to->top = moved;
	if (to->size == 0)
		to->bottom = moved;
	to->size++;
	return (1);
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	if (push_raw(a, b))
	{
		write(1, "pb\n", 3);
		bench->pb++;
		bench->total++;
	}
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	if (push_raw(b, a))
	{
		write(1, "pa\n", 3);
		bench->pa++;
		bench->total++;
	}
}
