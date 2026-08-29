/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:49:56 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/28 12:49:56 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_index(t_stack *stack)
{
	t_node	*node;
	t_node	*current;
	int		index;

	node = stack->top;
	while (node)
	{
		index = 0;
		current = stack->top;
		while (current)
		{
			if (current->value < node->value)
				index++;
			current = current->next;
		}
		node->index = index;
		node = node->next;
	}
}
