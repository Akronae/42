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

int read_to_env(t_env *env, int fd)
{
	char *buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	int bytes_read = read(fd, buffer, BUFFER_SIZE);
	char *joined = str_join(env->text_read, buffer, TRUE, TRUE);
	env->text_read = joined;
	return (bytes_read);
}

char *get_last_line(t_env *env)
{
	int text_read_len = str_index_of("\0", env->text_read);
	if ((int) env->last_byte < text_read_len)
	{
		char *s = (sub_str(env->text_read, env->last_byte, text_read_len));
		env->last_byte = text_read_len;
		return s;
	}
	return (NULL);
}

char *get_line (t_env *env, int fd)
{
	int bytes_read = read_to_env(env, fd);
	int next_eol_index = str_index_of("\n", env->text_read + env->last_byte);
	size_t previous_last_byte = env->last_byte;
	if (next_eol_index == INDEX_NOT_FOUND)
	{
		if (bytes_read <= 0)
			return (get_last_line(env));
		return get_line(env, fd);
	}
	else env->last_byte += next_eol_index + 1;
	return (sub_str(env->text_read, previous_last_byte, env->last_byte));
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
	return (get_line(env, fd));
}
