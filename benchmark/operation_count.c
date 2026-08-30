/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:34:53 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/21 18:34:53 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    bench_init(t_bench *bench)
{
    bench->total = 0;
    bench->sa = 0;
    bench->sb = 0;
    bench->ss = 0;
    bench->pa = 0;
    bench->pb = 0;
    bench->rr = 0;
    bench->ra = 0;
    bench->rb = 0;
    bench->rra = 0;
    bench->rrb = 0;
    bench->rrr = 0;
}
