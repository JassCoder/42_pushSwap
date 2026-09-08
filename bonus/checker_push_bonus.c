/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:55:55 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:56:01 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	bonus_pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || b->size == 0)
		return ;
	node = b->top;
	b->top = b->top->next;
	b->size--;
	if (b->size == 0)
		b->bottom = NULL;
	node->next = a->top;
	a->top = node;
	if (a->size == 0)
		a->bottom = node;
	a->size++;
}

void	bonus_pb(t_stack *a, t_stack *b)
{
	bonus_pa(b, a);
}
