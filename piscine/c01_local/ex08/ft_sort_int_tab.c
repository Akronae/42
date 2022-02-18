//
// Created by Alexandre DAUBRICOURT on 7/1/21.
//
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	a;
	int	b;

	i = -1;
	while (i++ < size - 2)
	{
		a = *(tab + i);
		b = *(tab + i + 1);
		if (a > b)
		{
			*(tab + i + 1) = a;
			*(tab + i) = b;
			i = -1;
		}
	}
}
