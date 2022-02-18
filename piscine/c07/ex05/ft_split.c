//
// Created by Alexandre DAUBRICOURT on 7/15/21.
//
#include <stdlib.h>

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
	return (-1);
}

char	*substr(char *str, int from, int to)
{
	int		i;
	char	*rtrn;

	if (from < 0)
		from = 0;
	if (to > str_len(str))
		to = str_len(str);
	rtrn = malloc(sizeof(char) * (to - from));
	i = -1;
	while (from + ++i < to)
	{
		rtrn[i] = str[from + i];
	}
	rtrn[i] = 0;
	return (rtrn);
}

char	**ft_split(char *str, char *charset)
{
	int		max_arr_size;
	char	**arr;
	int		arr_i;
	int		index_of_separator;

	if (str_len(charset) < 1)
		return (malloc(sizeof(0)));
	max_arr_size = str_len(str) / str_len(charset);
	arr = malloc(sizeof(int) * max_arr_size + sizeof(0));
	arr_i = -1;
	while (1)
	{
		index_of_separator = str_index_of(str, charset);
		if (index_of_separator == -1)
			break ;
		arr[++arr_i] = substr(str, 0, index_of_separator);
		str += index_of_separator + 1;
	}
	arr[++arr_i] = str;
	arr[++arr_i] = 0;
	return (arr);
}
