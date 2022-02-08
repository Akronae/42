//
// Created by Alexandre DAUBRICOURT on 6/30/21.
//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
