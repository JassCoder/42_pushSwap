/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:06:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/28 11:06:41 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
