/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:46:01 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 11:08:00 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	has_flag(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int	checker_sorted(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		return (0);
	return (is_sorted(a));
}

static int	checker_error(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc == 1)
		return (0);
	if (has_flag(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_init(&a);
	stack_init(&b);
	config_init(&config);
	if (!parse_args(argc, argv, &a, &config))
		return (checker_error(&a, &b));
	if (!checker_read(&a, &b))
		return (checker_error(&a, &b));
	if (checker_sorted(&a, &b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
