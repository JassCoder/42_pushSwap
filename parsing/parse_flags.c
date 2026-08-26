/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 23:09:22 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/26 18:28:36 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	config_init(t_config *config)
{
	config->strategy = ADAPTIVE;
	config->bench = 0;
	bench_init(&config->count);
}
int	parse_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strategy = ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		config->bench = 1;
	else
		return (0);
	return (1);
}
