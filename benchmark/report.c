/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:03:43 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/01 15:03:43 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*strategy_complexity(t_strategy strategy, double disorder)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	if (strategy == COMPLEX)
		return ("O(n log n)");
	if (disorder < 0.20)
		return ("O(n^2)");
	if (disorder < 0.50)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

static void	print_disorder(double disorder)
{
	int	value;
	int	decimal;

	value = (int)(disorder * 10000);
	decimal = value % 100;
	putstr_fd("Disorder: ", 2);
	putnbr_fd(value / 100, 2);
	putstr_fd(".", 2);
	if (decimal < 10)
		putstr_fd("0", 2);
	putnbr_fd(decimal, 2);
	putstr_fd("%\n", 2);
}

void	print_benchmark(t_config *config, double disorder)
{
	print_disorder(disorder);
	putstr_fd("Strategy: ", 2);
	putstr_fd(strategy_name(config->strategy), 2);
	putstr_fd("\nComplexity: ", 2);
	putstr_fd(strategy_complexity(config->strategy, disorder), 2);
	putstr_fd("\nTotal operations: ", 2);
	putnbr_fd(config->count.total, 2);
	putstr_fd("\n", 2);
	print_moves_count(config);
}
