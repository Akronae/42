//
// Created by Alexandre DAUBRICOURT on 7/8/21.
//
#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	sum;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	sum = nb;
	i = -1;
	while (++i < power - 1)
		sum *= nb;
	return (sum);
}
