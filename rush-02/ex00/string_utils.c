//
// Created by alexr on 7/11/2021.
//

#include <stdlib.h>
#include "constants.h"
#include "string_utils.h"
#include "math_utils.h"
#include "array_utils.h"
#include <stdio.h>

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
	rtrn = malloc(sizeof(char) * (to - from) + sizeof(0));
	if (rtrn == 0)
		return EMPTY_STRING;
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

char	*str_trim(char *str)
{
	char	*new_str;
	int		i;

	new_str = malloc(str_len(str) + sizeof(0));
	i = -1;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			new_str[++i] = *str;
		str++;
	}
	new_str[++i] = 0;
	return (new_str);
}

int	str_compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				break ;
		}
		else
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}