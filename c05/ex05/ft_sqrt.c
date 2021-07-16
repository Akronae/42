//
// Created by Alexandre DAUBRICOURT on 7/8/21.
//

int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	while (i <= nb / 2)
	{
		i += 2;
		if (i * i == nb)
			return (i);
	}
	return (0);
}
