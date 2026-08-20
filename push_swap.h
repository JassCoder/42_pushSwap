/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:16:01 by username          #+#    #+#             */
/*   Updated: 2026/08/19 19:54:40 by jsingh           ###   ########.fr       */
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
	struct s_node	*prev;
}	t_node;

typedef struct s_bench_count
{
	int	sa;
	int sb;
	int rra;
	int	total_op;
}	t_bench_count;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	t_bench_count *op;
	
}	t_stack;



// parsing
char	**ft_split(char *str, char c);
int	ft_strncmp(char *s1, char *s2, size_t len);
int	get_flags(int argc, char **argv, int *bench_mode);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

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
void	chunk_sort(t_stack *a, t_stack *b);
#endif
