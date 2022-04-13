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

long	read_line_to_env(char **env, int fd)
{
	char	*buffer;
	long	bytes_read;

	buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	env[fd] = str_join(env[fd], buffer, TRUE, TRUE);
	if (str_index_of("\n", env[fd]) != INDEX_NOT_FOUND || bytes_read <= 0)
		return (bytes_read);
	return (bytes_read + read_line_to_env(env, fd));
}

char	*get_line(char **env, int fd)
{
	int		index_of_nl;
	char	*str;
	char	*remaining;

	if (read_line_to_env(env, fd) <= 0 && !env[fd])
		return (NULL);
	index_of_nl = str_index_of("\n", env[fd]);
	str = (sub_str(env[fd], 0, index_of_nl));
	if (str_index_of("\0", str) == 0)
		safe_free(str);
	if (index_of_nl == INDEX_NOT_FOUND)
		remaining = NULL;
	else
		remaining = sub_str(env[fd], index_of_nl + 1, -1);
	safe_free(env[fd]);
	env[fd] = remaining;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*env[1024];

	if (fd < 0 || fd >= 1024)
		return (NULL);
	return (get_line(env, fd));
}
