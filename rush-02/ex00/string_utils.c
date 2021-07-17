//
// Created by alexr on 7/11/2021.
//

#include <stdlib.h>
#include "constants.h"
#include "string_utils.h"
#include "math_utils.h"
#include "array_utils.h"

int	str_len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	str_index_of(char *str, char *substr)
{
	int	i;
	int	substr_i;
	int	substr_len;

	substr_len = str_len(substr);
	i = -1;
	substr_i = -1;
	while (str[++i])
	{
		if (str[i] != substr[++substr_i])
		{
			substr_i = -1;
		}
		else if (substr_i == substr_len - 1)
		{
			return (i - substr_i);
		}
	}
	return (INDEX_NOT_FOUND);
}

char	*substr(char *str, int from, int to)
{
	int		i;
	char	*rtrn;

	from = val_max(from, 0);
	to = val_min(to, str_len(str));
	rtrn = malloc(sizeof(char) * (to - from));
	i = -1;
	while (from + ++i < to)
	{
		rtrn[i] = str[from + i];
	}
	rtrn[i] = 0;
	return (rtrn);
}

char	**str_split(char *str, char *separator)
{
	int		max_arr_size;
	char	**arr;
	int		arr_i;
	int		index_of_separator;

	max_arr_size = str_len(str) / str_len(separator);
	arr = new_array_int(max_arr_size);
	arr_i = -1;
	while (TRUE)
	{
		index_of_separator = str_index_of(str, separator);
		if (index_of_separator == INDEX_NOT_FOUND)
			break ;
		arr[++arr_i] = substr(str, 0, index_of_separator);
		str += index_of_separator + 1;
	}
	arr[++arr_i] = str;
	return (arr);
}
