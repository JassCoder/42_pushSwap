/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:15:24 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/09 22:15:24 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    // ! empty stack
    t_stack a;
    t_stack b;
    int strategy;
    int bench_mode;

    // ! check argument
    if (argc == 1)
    return (0);
    // ! initialize stack
    stack_init(&a);
    stack_init(&b);
    // ! checking sorting strategy (By default its adaptive)
    strategy = get_flags(argc, argv, &bench_mode);

    // ! clear at last
    clear_stack(&a);
    clear_stack(&b);
    return (0);
}