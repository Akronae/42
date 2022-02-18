//
// Created by Alexandre DAUBRICOURT on 7/3/21.
//

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
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
