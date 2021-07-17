//
// Created by Alexandre DAUBRICOURT on 7/17/21.
//
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int	get_file_size(char *path)
{
	int		f;
	char	c;
	int 	i;

	f = open(path, O_RDONLY);
	i = 0;
	while (read(f, &c, sizeof(c)))
		i += sizeof(c);
	close(f);
	return (i);
}

char	*read_file(char *path)
{
	int 	file_size;
	int		file_handle;
	char	*content;

	file_size = get_file_size(path);
	file_handle = open(path, O_RDONLY);
	content = malloc(file_size);
	read(file_handle, content, file_size);
	close(file_handle);
	return (content);
}