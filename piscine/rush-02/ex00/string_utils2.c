//
// Created by Alexandre DAUBRICOURT on 7/17/21.
//
#include "string_utils2.h"
#include <stdlib.h>
#include "string_utils.h"

char	*str_dup(char *src)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * str_len(src) + sizeof(0));
	i = 0;
	while (1)
	{
		copy[i] = src[i];
		if (src[i] == 0)
			break ;
		i++;
	}
	return (copy);
}

char	*str_copy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

char	*str_cat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = str_len(dest);
	i = -1;
	while (src[++i] != '\0')
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*str_catn(char *dest, char *src)
{
	char *new_str;

	new_str = malloc(sizeof(char) * (str_len(dest) + str_len(src)) + sizeof(0));
	str_copy(new_str, dest);
	str_cat(new_str, src);
	return (new_str);
}

char	*str_repeat(char *to_repeat, int count)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (str_len(to_repeat) * count) + sizeof(0));
	str[0] = 0;
	i = -1;
	while (++i < count)
	{
		str = str_catn(str, to_repeat);
	}
	return (str);
}