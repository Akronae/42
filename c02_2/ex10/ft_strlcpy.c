//
// Created by Alexandre DAUBRICOURT on 7/3/21.
//

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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0')
	{
		if (i < size)
			dest[i] = src[i];
		i++;
	}
	while (i <= size)
	{
		dest[i - 1] = '\0';
		i++;
	}
	dest[size - 1] = '\0';
	return (ft_strlen(src));
}
