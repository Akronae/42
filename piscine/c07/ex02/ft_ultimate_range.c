//
// Created by Alexandre DAUBRICOURT on 7/13/21.
//
#include <stdlib.h>

void	*new_array(int element_size, int element_count)
{
	void	**addr;
	int		i;

	addr = malloc(element_size * element_count + sizeof(0));
	i = -1;
	while (++i <= element_count + 1)
	{
		addr[i] = 0;
	}
	return (addr);
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	arr_size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr_size = abs(max - min);
	if (arr_size < 1)
		return (-1);
	*range = new_array(sizeof(int), arr_size);
	if (*range <= 0)
		return (-1);
	i = -1;
	while (++i < arr_size)
	{
		(*range)[i] = min + i;
	}
	return (arr_size);
}
