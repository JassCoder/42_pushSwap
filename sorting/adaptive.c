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

void	adaptive_sort(t_stack *a, t_stack *b, t_config *config)
{
	double	disorder;

	disorder = calculate_disorder(a);
	if (disorder < 0.2)
	{
		config->selected = SIMPLE;
		simple_sort(a, b, &config->count);
	}
	else if (disorder < 0.5)
	{
		config->selected = MEDIUM;
		medium_sort(a, b, &config->count);
	}
	else
	{
		config->selected = COMPLEX;
		complex_sort(a, b, &config->count);
	}
}
