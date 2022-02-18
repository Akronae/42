//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[++i] != '\0' && i < n)
	{
		dest[i] = '\0';
	}
	return (dest);
}
