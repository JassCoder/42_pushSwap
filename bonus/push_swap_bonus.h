/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:44:56 by jsingh            #+#    #+#             */
/*   Updated: 2026/09/08 10:44:58 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"

/* checker */
int		checker_read(t_stack *a, t_stack *b);
int		execute_instruction(char *line, t_stack *a, t_stack *b);

/* silent operations */
void	bonus_sa(t_stack *a);
void	bonus_sb(t_stack *b);
void	bonus_ss(t_stack *a, t_stack *b);
void	bonus_pa(t_stack *a, t_stack *b);
void	bonus_pb(t_stack *a, t_stack *b);
void	bonus_ra(t_stack *a);
void	bonus_rb(t_stack *b);
void	bonus_rr(t_stack *a, t_stack *b);
void	bonus_rra(t_stack *a);
void	bonus_rrb(t_stack *b);
void	bonus_rrr(t_stack *a, t_stack *b);

#endif