/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszkudla <mszkudla@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:16:01 by username          #+#    #+#             */
/*   Updated: 2026/08/03 19:18:49 by mszkudla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*last;
}	t_stack;
