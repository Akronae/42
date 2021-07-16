//
// Created by Alexandre DAUBRICOURT on 7/2/21.
//

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = -1;
	while (src[++i] != '\0' && i < (int) n)
	{
		dest[i] = src[i];
	}
	while (dest[++i] != '\0' && i < (int) n)
	{
		dest[i] = '\0';
	}
	return (dest);
}
