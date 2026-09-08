/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reverse_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:56:39 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:56:42 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	bonus_reverse(t_stack *stack)
{
	t_node	*before_last;

	if (!stack || stack->size < 2)
		return ;
	before_last = stack->top;
	while (before_last->next != stack->bottom)
		before_last = before_last->next;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = before_last;
	stack->bottom->next = NULL;
}

void	bonus_rra(t_stack *a)
{
	bonus_reverse(a);
}

void	bonus_rrb(t_stack *b)
{
	bonus_reverse(b);
}

void	bonus_rrr(t_stack *a, t_stack *b)
{
	bonus_rra(a);
	bonus_rrb(b);
}
