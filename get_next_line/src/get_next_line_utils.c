/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/03/23 15:09:47 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	str_index_of(char *to_find, char *in_str)
{
	size_t	in_str_i;
	size_t	to_find_i;

	in_str_i = 0;
	if (in_str == NULL || to_find == NULL)
		return (INDEX_NOT_FOUND);
	while (TRUE)
	{
		if (to_find[0] == '\0' && in_str[in_str_i] == '\0')
			return (in_str_i);
		if (!in_str[in_str_i])
			break ;
		to_find_i = 0;
		while (in_str[in_str_i + to_find_i] == to_find[to_find_i])
		{
			to_find_i++;
			if (!to_find[to_find_i])
				return (in_str_i);
		}
		in_str_i++;
	}
	return (INDEX_NOT_FOUND);
}

void	*ft_calloc(size_t size)
{
	char	*alloc;

	alloc = malloc(size);
	if (!alloc)
		return (NULL);
	while (size)
		alloc[--size] = 0;
	return (alloc);
}

void	safe_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

char	*str_join(char *s1, char *s2, int free_s1, int free_s2)
{
	size_t	i;
	int		s1_len;
	int		s2_len;
	char	*final;

	i = 0;
	s1_len = str_index_of("\0", s1);
	if (s1_len == INDEX_NOT_FOUND)
		s1_len = 0;
	s2_len = str_index_of("\0", s2);
	if (s2_len == INDEX_NOT_FOUND)
		s2_len = 0;
	final = ft_calloc((s1_len + s2_len + 1) * sizeof (char));
	while (s1 != NULL && *s1)
		final[i++] = *s1++;
	while (s2 != NULL && *s2)
		final[i++] = *s2++;
	if (free_s1)
		safe_free(s1 - s1_len);
	if (free_s2)
		safe_free(s2 - s2_len);
	return (final);
}

char	*sub_str(char *s, long from, long to)
{
	char	*new;
	long	i;

	if (to < 0)
		to = str_index_of("\0", s) + to;
	if (to < 0)
		to = 0;
	if (to > str_index_of("\0", s) - 1)
		to = str_index_of("\0", s) - 1;
	if (from > to)
		return (NULL);
	new = ft_calloc(to - from + 2);
	i = 0;
	if (!new)
		return (NULL);
	while (s[i] && i <= (to - from))
	{
		new[i] = s[from + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
