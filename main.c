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

static void	print_index_test(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		ft_printf("value: %d index: %d\n",
			current->value, current->index);
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
	print_test(&a);
	assign_index(&a);
	print_index_test(&a);
	print_test(&a);

	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
