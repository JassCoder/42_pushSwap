/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:33:15 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/30 23:33:15 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	double	disorder;

	disorder = calculate_disorder(a);
	if (disorder < 0.1)
		simple_sort(a, b, bench);
	else if(a->size < 430)
		medium_sort(a,b,bench);
	else
		complex_sort(a, b, bench);
	// if (disorder < 0.20)
	// 	simple_sort(a, b, bench);
	// else if (disorder < 0.50 )
	// 	medium_sort(a, b, bench);
	// else
	// 	complex_sort(a, b, bench);
}