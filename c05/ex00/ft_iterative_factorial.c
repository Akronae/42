//
// Created by Alexandre DAUBRICOURT on 7/8/21.
//
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	sum;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	sum = nb;
	while (--nb)
	{
		sum *= nb;
	}
	return (sum);
}
