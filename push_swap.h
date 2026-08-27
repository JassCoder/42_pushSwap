/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:16:01 by username          #+#    #+#             */
/*   Updated: 2026/08/27 17:44:51 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}	t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_bench
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
	t_bench		count;
}	t_config;

/* stack */
void	stack_init(t_stack *stack);
void	clear_stack(t_stack *stack);
/* Stack Utils*/
int		append_node(t_stack *stack, int value);
/* Parsing */
void	config_init(t_config *config);
int		parse_flag(char *arg, t_config *config);
int		is_valid_integer(char *str);
long	ft_atol(const char *str);
int		is_int_range(long value);
int		has_duplicate(t_stack *stack, int value);
int		parse_one_number(char *token, t_stack *a);
int		parse_number_group(char *arg, t_stack *a);
char	**ft_split(char *str, char c);
int		ft_strncmp(char *s1, char *s2, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	free_split(char **tokens);
int		parse_args(int argc, char **argv, t_stack *a, t_config *config);
/*Benchmark*/
void	bench_init(t_bench *count);
/*Operations swap / push / Rotate */
void	sa(t_stack *a, t_bench *bench);
void	sb(t_stack *b, t_bench *bench);
void	ss(t_stack	*a, t_stack *b, t_bench *bench);
void	pb(t_stack *a, t_stack *b, t_bench *bench);
void	pa(t_stack *b, t_stack *a, t_bench *bench);
void	ra(t_stack *a, t_bench *bench);
void	rb(t_stack *b, t_bench *bench);
void	rr(t_stack *a, t_stack *b, t_bench *bench);
#endif
