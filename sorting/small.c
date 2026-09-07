/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:56:48 by username          #+#    #+#             */
/*   Updated: 2026/09/07 13:34:07 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (first > second && first > third)
		ra(a, bench);
	else if (second > first && second > third)
		rra(a, bench);
	if (a->top->value > a->top->next->value)
		sa(a, bench);
}

void	small_sort(t_stack *a, t_bench *bench)
{
	if (a->size == 2)
		sa(a, bench);
	if (a->size == 3)
		sort3(a, bench);
}
