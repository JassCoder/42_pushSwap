/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:46:51 by username          #+#    #+#             */
/*   Updated: 2026/08/11 14:29:21 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	a;
	t_stack	b;

	int	arr[] =
	{
		42, 643, 24, 64, 72, 4124, 75, 884, 1534, 65, 7
	};
	stack_init(&a);
	stack_init(&b);
	stack_fill(&a, arr, 10);
	print_stack(&a);
	bubble_sort(&a, &b);
	print_stack(&a);
}
