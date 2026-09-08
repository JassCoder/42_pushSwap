/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:53:45 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:53:47 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	execute_swap(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		bonus_sa(a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		bonus_sb(b);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		bonus_ss(a, b);
	else
		return (0);
	return (1);
}

static int	execute_push(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		bonus_pa(a, b);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		bonus_pb(a, b);
	else
		return (0);
	return (1);
}

static int	execute_rotate(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		bonus_ra(a);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		bonus_rb(b);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		bonus_rr(a, b);
	else
		return (0);
	return (1);
}

static int	execute_reverse(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "rra\n", 5) == 0)
		bonus_rra(a);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		bonus_rrb(b);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		bonus_rrr(a, b);
	else
		return (0);
	return (1);
}

int	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (execute_swap(line, a, b))
		return (1);
	if (execute_push(line, a, b))
		return (1);
	if (execute_rotate(line, a, b))
		return (1);
	if (execute_reverse(line, a, b))
		return (1);
	return (0);
}
