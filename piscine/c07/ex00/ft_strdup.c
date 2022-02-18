//
// Created by Alexandre DAUBRICOURT on 7/12/21.
//
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(char *src)
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
