/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:18:15 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/11 14:47:31 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	str_index_of(char const *str, char const *substr)
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

static char	*substr(char const *str, int from, int to)
{
	int		i;
	char	*rtrn;

	if (from < 0)
		from = 0;
	if (to > ft_strlen(str))
		to = ft_strlen(str);
	rtrn = malloc(sizeof(char) * (to - from) + sizeof('\0'));
	if (!rtrn)
		return (NULL);
	i = -1;
	while (from + ++i < to)
	{
		rtrn[i] = str[from + i];
	}
	rtrn[i] = 0;
	return (rtrn);
}

static char	*ft_char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(c) * 1 + sizeof('\0'));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_i;
	int		index_of_separator;
	char	*charset;

	charset = ft_char_to_str(c);
	arr = malloc(sizeof(int) * (ft_strlen(s) / ft_strlen(charset)) + sizeof(0));
	if (!s || !arr || ft_strlen(charset) < 1)
		return (ft_calloc(sizeof(char *), 2));
	arr_i = -1;
	while (TRUE)
	{
		index_of_separator = str_index_of(s, charset);
		if (index_of_separator == 0 && s++)
			continue ;
		if (index_of_separator == INDEX_NOT_FOUND)
			break ;
		arr[++arr_i] = substr(s, 0, index_of_separator);
		s += index_of_separator;
	}
	if (s[0])
		arr[++arr_i] = ft_strdup((char *)s);
	arr[++arr_i] = NULL;
	free(charset);
	return (arr);
}
