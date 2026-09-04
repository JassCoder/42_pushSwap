/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:31:30 by username          #+#    #+#             */
/*   Updated: 2026/09/04 14:26:27 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append_node(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
	return (1);
}

