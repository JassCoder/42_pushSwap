/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 07:45:42 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 07:46:07 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
}

void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n > 9)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	print_basic_moves(t_config *config)
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
	putstr_fd("\n", 2);
}

static void	print_rotate_moves(t_config *config)
{
	putstr_fd("ra: ", 2);
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
	putstr_fd("\n", 2);
}

void	print_moves_count(t_config *config)
{
	print_basic_moves(config);
	print_rotate_moves(config);
}
