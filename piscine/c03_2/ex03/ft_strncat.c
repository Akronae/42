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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[b])
	{
		b++;
	}
	while (a < nb && src[a])
	{
		dest[b] = src[a];
		b++;
		a++;
	}
	dest[b] = 0;
	return (dest);
}
