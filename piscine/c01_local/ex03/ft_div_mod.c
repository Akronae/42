//
// Created by Alexandre DAUBRICOURT on 7/1/21.
//
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a - b * *div;
}
