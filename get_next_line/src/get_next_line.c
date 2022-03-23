/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/21 20:02:57 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	put_str(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	str_index_of (char *to_find, char *in_str)
{
	size_t in_str_i = 0;
	size_t to_find_i;

	if (in_str == NULL) return (INDEX_NOT_FOUND);
	while (in_str[in_str_i] || to_find[0] == '\0')
	{
		if (to_find[0] == '\0' && in_str[in_str_i] == '\0')
			return (in_str_i);
		to_find_i = 0;
		while (in_str[in_str_i] == to_find[to_find_i])
		{
			to_find_i++;
			if (!to_find[to_find_i])
				return (in_str_i);
		}
		in_str_i++;
	}
	return (INDEX_NOT_FOUND);
}

void *ft_calloc (size_t size)
{
	char *alloc = malloc(size);
	while (size)
	{
		alloc[--size] = 0;
	}
	return (alloc);
}

char *str_join(char *s1, char *s2, int free_s1, int free_s2)
{
	size_t i = 0;
	int s1_len = str_index_of("\0", s1);
	if (s1_len == INDEX_NOT_FOUND) s1_len = 0;
	int s2_len = str_index_of("\0", s2);
	if (s2_len == INDEX_NOT_FOUND) s2_len = 0;
	char *final = ft_calloc((s1_len + s2_len + 1) * sizeof (char));
	while (s1 != NULL && *s1) final[i++] = *s1++;
	while (s2 != NULL && *s2) final[i++] = *s2++;
	if (free_s1)
		free(s1 - s1_len);
	if (free_s2)
		free(s2 - s2_len);
	return (final);
}

char *sub_str(char *s, size_t from, size_t to)
{
	char *new = ft_calloc(to - from + 1);
	size_t i = 0;
	while (s[i] && i < (to - from))
	{
		new[i] = s[from + i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_env *env;
	if (env == NULL)
	{
		env = ft_calloc(sizeof(t_env));
		env->last_byte = 0;
		env->text_read = NULL;
	}
	char *buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		free(buffer);
		return (NULL);
	}
	char *joined = str_join(env->text_read, buffer, TRUE, TRUE);
	env->text_read = joined;
	size_t previous = env->last_byte;
	int eol_index = str_index_of("\n", env->text_read + env->last_byte);
	if (eol_index == INDEX_NOT_FOUND) return get_next_line(fd);
	else env->last_byte += eol_index + 1;
	return (sub_str(env->text_read, previous, eol_index + previous + 1));
}
