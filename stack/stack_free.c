/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:25:11 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/20 18:25:11 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    clear_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *next;

    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}