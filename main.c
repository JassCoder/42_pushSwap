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
    t_stack a;
    t_stack b;
    int strategy;
    int bench_mode;

    strategy = 3 || ; 
    bench_mode = 0; 

    if (argc == 1)
        return (0);
    stack_init(&a);
    stack_init(&b);
    // strategy = get_flags(argc, argv, &bench_mode);
    clear_stack(&a);
    clear_stack(&b);
    return (0);
}