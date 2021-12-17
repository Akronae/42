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

int	*ft_range(int min, int max)
{
	int	arr_size;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr_size = abs(max - min);
	arr = new_array(sizeof(int), arr_size);
	i = -1;
	while (++i < arr_size)
	{
		arr[i] = min + i;
	}
	return (arr);
}
