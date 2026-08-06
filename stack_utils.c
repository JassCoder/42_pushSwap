/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:31:30 by username          #+#    #+#             */
/*   Updated: 2026/08/06 16:15:27 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	append_node(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	new->prev = stack->bottom;
	if (stack->top == NULL)
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

void	clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;
	int		i;

	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	stack_init(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->top;
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}
