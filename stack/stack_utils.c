/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:31:30 by username          #+#    #+#             */
/*   Updated: 2026/08/20 17:54:30 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	append_node(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return(0);
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

void	clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

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

	node = stack->top;
	while (node)
	{
		ft_printf("val:%d i:%d\n", node->value, node->index);
		node = node->next;
	}
	ft_printf("\n");
}
