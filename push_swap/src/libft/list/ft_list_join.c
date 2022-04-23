/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../string/ft_string.h"
#include "../number/ft_number.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"

static size_t	ft_compute_join_length(t_iterator *iterator, char *delimiter)
{
	size_t	total_length;

	total_length = 1;
	while (iterator->current)
	{
		if (iterator->current->data_type == T_TYPE_UNKNOWN)
			total_length += ft_strlen(T_TYPE_UNKNOWN_STR);
		else if (iterator->current->data_type == T_TYPE_STRING)
			total_length += ft_strlen(iterator->current->data_str);
		else if (iterator->current->data_type == T_TYPE_CHAR)
			total_length += 1;
		else
			ft_exit_err(ft_strjoin("ft_compute_join_length: cannot parse type ",
								   ft_number_to_str(iterator->current->data_type)));
		total_length += ft_strlen(delimiter);
		iterator->next(iterator);
	}
	total_length -= ft_strlen(delimiter);
	return (total_length);
}

char	*ft_list_join(t_list *self, char *delimiter)
{
	t_iterator	*iterator;
	char		*str;

	iterator = self->get_iterator(self);
	str = ft_safe_malloc(sizeof (char)
			* ft_compute_join_length(iterator, delimiter));
	iterator->reset(iterator);
	while (iterator->current)
	{
		if (iterator->current->data_type == T_TYPE_UNKNOWN)
			ft_string_append(str, T_TYPE_UNKNOWN_STR);
		else if (iterator->current->data_type == T_TYPE_STRING)
			ft_string_append(str, iterator->current->data_str);
		else if (iterator->current->data_type == T_TYPE_CHAR)
			ft_string_append_char(str, *iterator->current->data_str);
		else
			ft_exit_err(ft_strjoin("ft_list_join: cannot parse type ",
								   ft_number_to_str(iterator->current->data_type)));
		ft_string_append(str, delimiter);
		iterator->next(iterator);
	}
	iterator->free(iterator);
	return (str);
}
