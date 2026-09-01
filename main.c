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

#include "push_swap.h"

static void	run_strategy(t_stack *a, t_stack *b, t_config *config)
{
	if (config->strategy == SIMPLE)
		simple_sort(a, b, &config->count);
	else if (config->strategy == MEDIUM)
		medium_sort(a, b, &config->count);
	else if (config->strategy == COMPLEX)
		complex_sort(a, b, &config->count);
	else
		adaptive_sort(a, b, &config->count);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;
	double		disorder;

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
	disorder = calculate_disorder(&a);
	if (!is_sorted(&a))
		run_strategy(&a, &b, &config);
	if (config.bench)
		print_benchmark(&config, disorder);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
