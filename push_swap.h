/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:16:01 by username          #+#    #+#             */
/*   Updated: 2026/08/12 14:34:50 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// parsing
char	**ft_split(char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		get_flags(int argc, char **argv, int *bench_mode);

void	stack_init(t_stack *stack);
int		stack_fill(t_stack *stack, int *arr, int size);
int		append_node(t_stack *stack, int value);
void	clear_stack(t_stack *stack);
void	print_stack(t_stack *stack);
float	compute_disorder(t_stack *stack);
// swap operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
// push operations
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
// rotate operations
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
// reverse rotate operations
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
// sorting algorythms

void	selection_sort(t_stack *a, t_stack *b);
#endif
