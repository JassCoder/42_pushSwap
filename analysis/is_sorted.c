/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   is_sorted.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/28 10:34:12 by username         #+#    #+#              */
/*   Updated: 2026/09/03 12:57:05 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (0);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
