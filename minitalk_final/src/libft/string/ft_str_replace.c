/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:27:10 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"
#include "../io/ft_io.h"

t_str	ft_str_replace(t_str s, t_str find, t_str replacement)
{
	t_list	*list;
	t_str	replaced;

	if (ft_str_index_of(s, find) == INDEX_NOT_FOUND)
		return (ft_strdup(s));
	list = ft_split_list(s, find);
	if (ft_str_starts_with(s, find))
		list->insert_data_at(list, 0, ft_s(""));
	if (ft_str_ends_with(s, find))
		list->push_str(list, ft_strdup(""));
	replaced = list->join(list, replacement);
	list->free(list);
	return (replaced);
}
