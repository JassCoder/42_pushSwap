/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:17:59 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/12 19:17:59 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strncmp(char *s1, char *s2, size_t len)
{
    int i;

    i = 0;
    while (i < len && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (i == len)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}