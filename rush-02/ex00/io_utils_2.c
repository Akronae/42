//
// Created by alexr on 7/11/2021.
//

#include "io_utils_2.h"
#include "io_utils.h"
#include "constants.h"

void	putarrayint(int *arr)
{
	int	i;

	putstr("[");
	i = -1;
	while (arr[++i] != UNDEFINED)
	{
		putnbr(arr[i]);
		if (arr[i + 1] != UNDEFINED)
			putstr(", ");
	}
	putstr("]");
}

void	putarray_2_int(int **arr)
{
	int	i;
	int	j;

	putstr("[");
	i = -1;
	while (arr[++i] != UNDEFINED)
	{
		putarrayint(arr[i]);
		nl();
	}
	putstr("]");
}
