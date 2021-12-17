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
	int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	while (src[++i] != '\0')
	{
		if (i < (int) size)
			dest[i] = src[i];
	}
	while (++i <= (int) size + 10)
	{
		dest[i - 1] = '\0';
	}
	dest[size - 1] = '\0';
	return (ft_strlen(src));
}
