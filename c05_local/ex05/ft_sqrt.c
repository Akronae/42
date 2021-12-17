//
// Created by Alexandre DAUBRICOURT on 7/8/21.
//

int	ft_sqrt(int nb)
{
	int	i;

	if (nb == 1)
		return (1);
	i = 1;
	while (i <= nb / i && i <= 46340)
	{
		i += 1;
		if (i * i == nb)
			return (i);
	}
	return (0);
}
