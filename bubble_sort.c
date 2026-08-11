/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:35:09 by username          #+#    #+#             */
/*   Updated: 2026/08/11 14:35:28 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	n;

	n = a->size;
	while (n > 1)
	{
		i = 0;
		while (i < n - 1)
		{
			if (a->top->value > a->top->next->value)
				sa(a);
			pb(a, b);
			i++;
		}
		while (i > 0)
		{
			pa(a, b);
			i--;
		}
		n--;
	}
}
