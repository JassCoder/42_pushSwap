#include "push_swap.h"

void stack_init(t_node **stack, int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        append_node(stack, arr[i]);
        i++;
    }
}

int main(void)
{
    int arr[] = {5, 8, 42, 90, 435};
    t_node *stack;

    stack = NULL;
    stack_init(&stack, arr, 5);
    print_stack(stack);
    return (0);
}
