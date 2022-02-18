//
// Created by Alexandre DAUBRICOURT on 7/3/21.
//

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				break ;
		}
		else
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
