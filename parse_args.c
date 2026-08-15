/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 01:17:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/15 01:17:41 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 01:17:41 by jsingh            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	is_valid_integer(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_number(char *str, t_stack *a)
{
	long	value;

	if (!is_valid_integer(str))
		return (0);
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	if (has_duplicate(a, (int)value))
		return (0);
	if (!append_node(a, (int)value))
		return (0);
	return (1);
}

static int	parse_numbers(char **numbers, t_stack *a)
{
	int	j;

	j = 0;
	while (numbers[j])
	{
		if (!parse_number(numbers[j], a))
			return (0);
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	**numbers;
	int		i;
	int		added;

	i = 1;
	added = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			i++;
			continue ;
		}
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (0);
		if (!numbers[0])
		{
			free_split(numbers);
			return (0);
		}
		if (!parse_numbers(numbers, a))
		{
			free_split(numbers);
			return (0);
		}
		added = 1;
		free_split(numbers);
		i++;
	}
	if (!added)
		return (0);
	return (1);
}