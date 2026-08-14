/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:21:50 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/13 12:21:50 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
