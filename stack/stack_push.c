/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:32:44 by username          #+#    #+#             */
/*   Updated: 2026/08/06 16:15:24 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*detach_top(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = node->next;
		stack->top->prev = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

static void	attach_top(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		node->next = NULL;
		node->prev = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = NULL;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*node;

	node = detach_top(src);
	if (node)
		attach_top(dest, node);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
