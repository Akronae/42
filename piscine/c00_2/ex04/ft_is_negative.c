//
// Created by Alexandre DAUBRICOURT on 6/30/21.
//
#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(0, "P", 1);
	}
}
