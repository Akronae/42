//
// Created by alexr on 7/11/2021.
//

#include <stdlib.h>
#include "array_utils.h"
#include "constants.h"

void	*new_array(int element_size, int element_count)
{
	void	**addr;
	int		i;

	addr = malloc(element_size * element_count + sizeof(UNDEFINED));
	i = -1;
	while (++i <= element_count + 1)
	{
		addr[i] = UNDEFINED;
	}
	return (addr);
}

void	**new_array_2(int element_size, int dim_1_size, int dim_2_size)
{
	void	***addr;
	int		i;

	addr = new_array(sizeof(int), dim_1_size);
	i = -1;
	while (++i <= dim_1_size)
	{
		addr[i] = new_array(element_size, dim_2_size);
	}
	addr[++i] = UNDEFINED;
	return (addr);
}

void	*new_array_int(int element_count)
{
	return (new_array(sizeof(int), element_count));
}

int	get_array_size(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != UNDEFINED)
		;
	return (i);
}
