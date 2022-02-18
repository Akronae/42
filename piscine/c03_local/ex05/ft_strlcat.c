//
// Created by Alexandre DAUBRICOURT on 7/3/21.
//
#include <unistd.h>

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	i;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_length);
	if (size <= dest_length)
		return (src_length + size);
	while (src[i] && dest_length + 1 < size & i + 1 < size)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = 0;
	return (dest_length + src_length);
}
