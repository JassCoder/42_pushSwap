/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/26 23:54:38 by username         #+#    #+#              */
/*   Updated: 2026/09/03 12:27:56 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_raw(t_stack *stack)
{
	t_node	*first;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	stack->top = first->next;
	stack->bottom->next = first;
	first->next = NULL;
	stack->bottom = first;
	return (1);
}

void	ra(t_stack *a, t_bench *bench)
{
	if (rotate_raw(a))
	{
		write(1, "ra\n", 3);
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_stack *b, t_bench *bench)
{
	if (rotate_raw(b))
	{
		write(1, "rb\n", 3);
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	int	changed;

	changed = 0;
	if (rotate_raw(a))
		changed = 1;
	if (rotate_raw(b))
		changed = 1;
	if (changed)
	{
		write(1, "rr\n", 3);
		bench->rr++;
		bench->total++;
	}
}
