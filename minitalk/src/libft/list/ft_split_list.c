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
#include <stdlib.h>

t_list	*ft_split_list(t_string s, char c)
{
	t_list	*list;
	t_string 	*split;

	split = ft_split(s, c);
	list = new_list();
	while (*split)
	{
		list->push_str(list, ft_strdup(*split));
		ft_safe_free(*split);
		split++;
	}
	ft_safe_free(split - list->length);
	return (list);
}
