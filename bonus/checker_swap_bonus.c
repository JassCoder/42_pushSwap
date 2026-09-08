/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:55:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:55:44 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	bonus_sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	if (a->size == 2)
		a->bottom = first;
}

void	bonus_sb(t_stack *b)
{
	bonus_sa(b);
}

void	bonus_ss(t_stack *a, t_stack *b)
{
	bonus_sa(a);
	bonus_sb(b);
}
