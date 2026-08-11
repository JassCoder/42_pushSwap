/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 00:41:38 by jsingh            #+#    #+#             */
/*   Updated: 2026/08/11 00:41:38 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t   count_token(char const *str, char c)
{
    size_t  in_word;
    size_t  i;
    size_t  token;

    in_word = 0;
    token = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if ( str[i] != c && in_word == 0)
        {
            in_word = 1;
            token++;
        }
        else if (str[i] == c)
        {
            in_word = 0;
        }
        i++;
    }
    return (token);
}

static size_t	char_len(char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static void free_space(char **array, int i)
{
    while (i >= 0)
    {
        free(array[i]);
        i--;
    }
    free(array);
}

static char **fill_array(char *str, char c, char **array, size_t token)
{
    size_t      i;
    size_t      len;

    i = 0;
    while (i < token)
    {
        while (*str == c)
            str++;
        len = char_len(str, c);
        array[i] = malloc(len + 1);
        if (!array[i])
        {
            free_space(array, i - 1);
            return (NULL);
        }
        ft_strlcpy(array[i], str, (len + 1));
        str += len;
        i++;
    }
    array[i] = NULL;
    return (array);
}

char    **ft_split(char *str, char c)
{
    char        **array;
    size_t      token;

    if (!str)
        return (NULL);
    token = count_token(str, c);
    array = malloc((token + 1) * sizeof(char *));
    if (!array)
        return (NULL);
    return (fill_array(str, c, array, token));
}
