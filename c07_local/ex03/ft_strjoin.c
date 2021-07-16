//
// Created by Alexandre DAUBRICOURT on 7/13/21.
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

int	get_sizeof_str_arr(char **arr, int arr_size)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (++i < arr_size)
	{
		size += str_len(arr[i]);
	}
	return (size);
}

char	*ft_strcat(char *dest, char *src)
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (get_sizeof_str_arr(strs, size)
				+ str_len(sep)));
	str[0] = 0;
	if (size < 1 || str == NULL)
		return (str);
	i = -1;
	while (++i < size)
	{
		if (i > 0)
			ft_strcat(str, sep);
		ft_strcat(str, strs[i]);
	}
	return (str);
}
