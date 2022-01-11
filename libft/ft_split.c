/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:18:15 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/11 12:18:46 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	str_index_of(char *str, char *substr)
{
	int	i;
	int	substr_i;
	int	substr_len;

	substr_len = ft_strlen(substr);
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

	if (from < 0)
		from = 0;
	if (to > ft_strlen(str))
		to = ft_strlen(str);
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

	if (ft_strlen(charset) < 1)
		return (malloc(sizeof(0)));
	max_arr_size = ft_strlen(str) / ft_strlen(charset);
	arr = malloc(sizeof(int) * max_arr_size + sizeof(0));
	arr_i = -1;
	while (TRUE)
	{
		index_of_separator = str_index_of(str, charset);
		if (index_of_separator == INDEX_NOT_FOUND)
			break ;
		arr[++arr_i] = substr(str, 0, index_of_separator);
		str += index_of_separator + 1;
	}
	arr[++arr_i] = str;
	arr[++arr_i] = 0;
	return (arr);
}
