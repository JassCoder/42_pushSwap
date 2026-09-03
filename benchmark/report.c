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

static char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	if (strategy == COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

static void	putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

static void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n > 9)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	print_benchmark(t_config *config, double disorder)
{
	(void)disorder;
	putstr_fd("Disorder: ",2);
	putnbr_fd((disorder*1000)/10, 2);
	putstr_fd(".", 2);
	putnbr_fd((int)(disorder*1000)%100,2);
	putstr_fd("%\n",2);
	putstr_fd("Strategy: ", 2);
	putstr_fd(strategy_name(config->strategy), 2);
	putstr_fd("\nComplexity: ", 2);
	putstr_fd(strategy_complexity(config->strategy), 2);
	putstr_fd("\nTotal operations: ", 2);
	putnbr_fd(config->count.total, 2);
	putstr_fd("\n", 2);
}
