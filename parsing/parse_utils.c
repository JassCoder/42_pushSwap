/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:54:50 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/20 18:54:50 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	will_overflow(long result, int digit, long limit)
{
	if (result > limit / 10)
		return (1);
	if (result == limit / 10 && digit > limit % 10)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	limit;
	int		sign;
	int		i;
	int		digit;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = get_sign(str, &i);
	limit = 2147483647L;
	if (sign == -1)
		limit = 2147483648L;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i++] - '0';
		if (will_overflow(result, digit, limit))
			return (2147483648L);
		result = result * 10 + digit;
	}
	return (result * sign);
}

int	is_int_range(long value)
{
	if (value < -2147483648L || value > 2147483647L)
		return (0);
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}
