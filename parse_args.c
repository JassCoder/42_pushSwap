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
#include <limits.h>


static  int flag_check(int argc, char **argv)
{
    int i;

    i = 1;
    if (ft_strncmp(argv[i],"--", 2) == 0)
        return (0);
    else
        return (1);
}

int parse_arg(int argc, char **argv)
{
    int     i;
    int     j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (ft_strncmp(argv[i], "--", 2) == 0)


    }
    
}