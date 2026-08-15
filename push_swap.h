/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:16:01 by username          #+#    #+#             */
/*   Updated: 2026/08/15 07:02:38 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* Parsing */
char	**ft_split(char *str, char c);
void	free_split(char **split);
int		strncmp(const char *s1, const char *s2, size_t len);
long	atol(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		parse_args(int argc, char **argv, t_stack *a);
int		get_flags(int argc, char **argv, int *bench_mode);
int		has_duplicate(t_stack *a, int value);
/* Stack */
void	stack_init(t_stack *stack);
int		stack_fill(t_stack *stack, int *arr, int size);
int		append_node(t_stack *stack, int value);
void	clear_stack(t_stack *stack);
void	print_stack(t_stack *stack);
float	compute_disorder(t_stack *stack);
/* Swap */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
/* Push */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
/* Rotate */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
/* Reverse rotate */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
/* Sorting */
void	selection_sort(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b);
#endif
