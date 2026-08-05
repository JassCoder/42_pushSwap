#include "push_swap.h"
#include <stdlib.h>

void append_node(t_node **stack, int num)
{
    t_node *last;
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return ;
    new->value = num;
    new->next = NULL;
    new->prev = NULL;
    if (*stack == NULL)
    {
        *stack = new;
        return ;
    }
    last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    new->prev = last;
}

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// push()
// pop()

