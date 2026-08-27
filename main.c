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

static void	print_test(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc == 1)
		return (0);
	stack_init(&a);
	stack_init(&b);
	config_init(&config);
	if (!parse_args(argc, argv, &a, &config))
	{
		clear_stack(&a);
		clear_stack(&b);
		write(2, "Error\n", 6);
		return (1);
	}
	pb(&a, &b, &config.count);
	pb(&a, &b, &config.count);

	ft_printf("A BEFORE RR:\n");
	print_test(&a);

	ft_printf("B BEFORE RR:\n");
	print_test(&b);

	rr(&a, &b, &config.count);

	ft_printf("A AFTER RR:\n");
	print_test(&a);

	ft_printf("B AFTER RR:\n");
	print_test(&b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
