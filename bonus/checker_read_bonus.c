/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:50:58 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:52:26 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	process_char(char *buffer, int *index, t_stack *a, t_stack *b)
{
	if (buffer[*index] == '\n')
	{
		buffer[*index + 1] = '\0';
		if (!execute_instruction(buffer, a, b))
			return (0);
		*index = 0;
	}
	else
	{
		(*index)++;
		if (*index >= 14)
			return (0);
	}
	return (1);
}

int	checker_read(t_stack *a, t_stack *b)
{
	char	buffer[16];
	int		index;
	ssize_t	bytes;

	index = 0;
	bytes = read(0, &buffer[index], 1);
	while (bytes > 0)
	{
		if (!process_char(buffer, &index, a, b))
			return (0);
		bytes = read(0, &buffer[index], 1);
	}
	if (index != 0)
		return (0);
	return (1);
}
