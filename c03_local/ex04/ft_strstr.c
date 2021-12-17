//
// Created by Alexandre DAUBRICOURT on 7/5/21.
//
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	find_idx;

	i = -1;
	find_idx = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[++i])
	{
		if (str[i] == to_find[find_idx])
			find_idx++;
		else
			find_idx = 0;
		if (find_idx == ft_strlen(to_find))
			return (str + i - find_idx + 1);
	}
	return (NULL);
}
