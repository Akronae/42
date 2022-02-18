//
// Created by Alexandre DAUBRICOURT on 7/9/21.
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

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}
