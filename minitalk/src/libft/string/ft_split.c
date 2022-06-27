/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:18:15 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_str 	ft_strndup(t_str s, size_t n)
{
	size_t	i;
	t_str 	result;

	result = (t_str ) ft_safe_malloc(sizeof(char) * (n + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static size_t	ft_wordlen(t_str s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static size_t	ft_count_word(t_str s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

void	*ft_free_split(t_str *s, int cnt)
{
	while (cnt--)
		ft_safe_free(s[cnt]);
	ft_safe_free(s);
	return (NULL);
}

t_str 	*ft_split(t_str s, char c)
{
	t_str 	*result;
	size_t	count;
	size_t	wordlen;
	size_t	i;

	if (!s || !c)
		return (ft_calloc(sizeof(t_str )));
	count = ft_count_word(s, c);
	result = (t_str *)ft_safe_malloc(sizeof(t_str ) * (count + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		result[i] = ft_strndup(s, wordlen);
		if (!result[i])
			return (ft_free_split(result, i - 1));
		s += wordlen;
		i++;
	}
	result[count] = 0;
	return (result);
}
