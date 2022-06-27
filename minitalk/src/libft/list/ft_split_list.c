/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:18:15 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../libft.h"
#include <stdlib.h>

t_list	*ft_split_list(t_str s, t_str separator)
{
	t_list	*list;
	size_t	index;
	size_t	separator_len;

	list = new_list();
	separator_len = ft_strlen(separator);
	while (*s)
	{
		index = ft_str_index_of(s, separator);
		if (index == 0)
			s += separator_len;
		else if ((int) index == INDEX_NOT_FOUND)
		{
			list->push_str(list, ft_strdup(s));
			break ;
		}
		else
		{
			list->push_str(list, ft_substr(s, 0, index - 1));
			s += index + separator_len;
		}
	}
	return (list);
}
