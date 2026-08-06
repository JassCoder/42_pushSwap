/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:31:19 by username          #+#    #+#             */
/*   Updated: 2026/08/06 17:05:20 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	stack_fill(t_stack *stack, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!append_node(stack, arr[i]))
		{
			clear_stack(stack);
			return (0);
		}
		i++;
	}
	return (1);
}
