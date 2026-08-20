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

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
int	is_int_range(long value)
{
    if (value < -2147483648L || value > 2147483647L)
		return (0);
	return (1);
}
int has_duplicate(t_stack *stack, int value)
{
    t_node *current;

    current = stack->top;
    while (current)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}
    