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

void print_moves_count(t_config *config)
{
	putstr_fd("pa: ", 2);
	putnbr_fd(config->count.pa, 2);
	putstr_fd(" pb: ", 2);
	putnbr_fd(config->count.pb, 2);
	putstr_fd("\nsa: ", 2);
	putnbr_fd(config->count.sa, 2);
	putstr_fd(" sb: ", 2);
	putnbr_fd(config->count.sb, 2);
	putstr_fd(" ss: ", 2);
	putnbr_fd(config->count.ss, 2);
	putstr_fd("\nra: ", 2);
	putnbr_fd(config->count.ra, 2);
	putstr_fd(" rb: ", 2);
	putnbr_fd(config->count.rb, 2);
	putstr_fd(" rr: ", 2);
	putnbr_fd(config->count.rr, 2);
	putstr_fd("\nrra: ", 2);
	putnbr_fd(config->count.rra, 2);
	putstr_fd(" rrb: ", 2);
	putnbr_fd(config->count.rrb, 2);
	putstr_fd(" rrr: ", 2);
	putnbr_fd(config->count.rrr, 2);
}

void	print_benchmark(t_config *config, double disorder)
{
	(void)disorder;
	putstr_fd("Disorder: ",2);
	putnbr_fd((disorder*1000)/10, 2);
	putstr_fd(".", 2);
	putnbr_fd((int)(disorder*1000)%100, 2);
	putstr_fd("%\n",2);
	putstr_fd("Strategy: ", 2);
	putstr_fd(strategy_name(config->strategy), 2);
	putstr_fd("\nComplexity: ", 2);
	putstr_fd(strategy_complexity(config->strategy), 2);
	putstr_fd("\nTotal operations: ", 2);
	putnbr_fd(config->count.total, 2);
	putstr_fd("\n", 2);
	print_moves_count(config);
}
