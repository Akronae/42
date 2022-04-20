/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/03/23 15:15:11 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_memcpy(char *src, char *dst, long from, long to)
{
	long	i;

	if (!src || !dst)
		return ;
	if (to < 0)
		to = str_index_of("\0", src) + to;
	if (to < 0)
		to = 0;
	i = 0;
	while (src[i] && from + i <= to)
	{
		dst[i] = src[from + i];
		i++;
	}
	dst[i] = 0;
}

long	read_line_to_env(char *env, int fd)
{
	char	*buffer;
	long	bytes_read;
	char	*joined;

	buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	joined = str_join(env, buffer, FALSE, TRUE);
	ft_memcpy(joined, env, 0, -1);
	safe_free(joined);
	if (str_index_of("\n", env) != INDEX_NOT_FOUND || bytes_read <= 0)
		return (bytes_read);
	return (bytes_read + read_line_to_env(env, fd));
}

char	*get_line(char *env, int fd)
{
	int		index_of_nl;
	char	*str;
	char	*remaining;

	if (read_line_to_env(env, fd) <= 0 && !env[0])
		return (NULL);
	index_of_nl = str_index_of("\n", env);
	str = (sub_str(env, 0, index_of_nl));
	if (str_index_of("\0", str) == 0)
		safe_free(str);
	if (index_of_nl == INDEX_NOT_FOUND)
		remaining = NULL;
	else
		remaining = sub_str(env, index_of_nl + 1, -1);
	if (remaining == NULL)
		env[0] = 0;
	ft_memcpy(remaining, env, 0, -1);
	safe_free(remaining);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	env[1024][BUFFER_SIZE];

	if (fd < 0 || fd >= 1024)
		return (NULL);
	return (get_line(env[fd], fd));
}
