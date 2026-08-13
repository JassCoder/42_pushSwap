/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:35:09 by username          #+#    #+#             */
/*   Updated: 2026/08/12 14:36:25 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stack *stack)
{
	int		min;
	t_node	*i;

	i = stack->top;
	min = i->value;
	while (i)
	{
		if (i->value < min)
			min = i->value;
		i = i->next;
	}
	return (min);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	min_value;
	int	size;

	while (a->top)
	{
		min_value = find_min_value(a);
		while (a->top->value != min_value)
			ra(a);
		pb(a, b);
	}
	while (b->top)
		pa(a, b);
}
