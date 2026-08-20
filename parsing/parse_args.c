/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 01:17:41 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/15 01:17:41 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_one_number(char *token, t_stack *a)
{
    long    value;

    if (!is_valid_integer(token))
        return (0);
    value = ft_atol(token);
    if (!is_int_range(token))
        return (0);
    if (has_duplicate(a, (int)value))
        return (0);
    if (!append_node(a, (int)value))
        return (0);
    return (1);
}

int	parse_number_group(char *arg, t_stack *a)
{
    char    **tokens;
    int     i;

    tokens = ft_split(arg, ' ');
    if (!tokens)
        return (0);
    i = 0;
    while (tokens[i])
    {
        if (!parse_one_number(tokens[i], a))
        {
            free_split(tokens);
            return (0);
        }
        i++;
    }
    free_split(tokens);
    return (1);
}
int parse_args(int argc, char **argv, t_stack *a, t_config *config)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (parse_flag(argv[i], config))
            i++;
        else
        {
            if (argv[i][0] == '-' && argv[i][1] == '-')
                return (0);
            if (!parse_number_group(argv[i], a))
                return (0);
            i++;
        }
    }
    if (a->size == 0)
        return (0);
    return (1);
}
