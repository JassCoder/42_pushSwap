/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:56:26 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:56:29 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	bonus_rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	stack->bottom->next = first;
	stack->bottom = first;
}

void	bonus_ra(t_stack *a)
{
	bonus_rotate(a);
}

void	bonus_rb(t_stack *b)
{
	bonus_rotate(b);
}

void	bonus_rr(t_stack *a, t_stack *b)
{
	bonus_ra(a);
	bonus_rb(b);
}
