/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 23:09:22 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/19 19:35:36 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_flags(int argc, char **argv, int *bench_mode)
{
	int	i;
	int strategy;

	strategy = 3;
	*bench_mode = 0;
	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i] , "--simple", 9) == 0)
			strategy = 0;
		if (ft_strncmp(argv[i] , "--medium", 9) == 0)
			strategy = 1;
		if (ft_strncmp(argv[i] , "--complex", 10) == 0)
			strategy = 2;
		if (ft_strncmp(argv[i] , "--adaptive", 11) == 0)
			strategy = 3;
		if (ft_strncmp(argv[i] , "--bench", 8) == 0)
			*bench_mode = 1;
		else
			return (-1);
		i++;	
	}
	return (strategy);
}

