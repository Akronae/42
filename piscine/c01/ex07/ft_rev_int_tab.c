//
// Created by Alexandre DAUBRICOURT on 7/1/21.
//
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	opposed_index;
	int	temp;

	i = -1;
	while (i++ < (size - 1) / 2)
	{
		opposed_index = size - i - 1;
		temp = *(tab + i);
		*(tab + i) = *(tab + opposed_index);
		*(tab + opposed_index) = temp;
	}
}
