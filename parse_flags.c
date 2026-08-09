/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 23:09:22 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/10 00:01:02 by jsingh           ###   ########.fr       */
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
		if (ft_strncmp(argv[i] , "--simple", 8) == 0)
			strategy = 0;
		if (ft_strncmp(argv[i] , "--medium", 8) == 0)
			strategy = 1;
		if (ft_strncmp(argv[i] , "--complex", 9) == 0)
			strategy = 2;
		if (ft_strncmp(argv[i] , "--adaptive", 10) == 0)
			strategy = 3;
		if (ft_strncmp(argv[i] , "--bench", 7) == 0)
			*bench_mode = 1;
		else
			break;
		i++;	
	}
	return (strategy);
}
