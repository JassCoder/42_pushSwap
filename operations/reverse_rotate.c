/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:51:40 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/27 17:51:40 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  reverse_rotate_raw(t_stack *stack)
{
    t_node  *before_last;
    t_node  *last;

    if (stack->size < 2)
        return (0);
    before_last = stack->top;
    while (before_last->next != stack->bottom)
        before_last = before_last->next;
    last = stack->bottom;
    before_last->next = NULL;
    stack->bottom = before_last;
    last->next = stack->top;
    stack->top = last;
    return (1);
}

void    rra(t_stack *a, t_bench *bench)
{
    if (reverse_rotate_raw(a))
    {
        write(1, "rra\n", 4);
        bench->rra++;
        bench->total++;
    }
}
void    rrb(t_stack *b, t_bench *bench)
{
    if (reverse_rotate_raw(b))
    {
        write(1, "rrb\n", 4);
        bench->rrb++;
        bench->total++;
    }
}

void    rrr(t_stack *a, t_stack *b, t_bench *bench)
{
    int changed;

    changed = 0;
    if (reverse_rotate_raw(a))
        changed = 1;
    if (reverse_rotate_raw(b))
        changed = 1;
    if (changed)
    {
        write(1, "rrr\n", 4);
        bench->rrr++;
        bench->total++;
    }
}
