/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../string/ft_string.h"
#include "../memory/ft_memory.h"

static size_t	ft_compute_join_length(t_iterator *iterator, char *delimiter)
{
	size_t	total_length;

	total_length = 1;
	while (iterator->current)
	{
		if (iterator->current->data_type == T_TYPE_STRING)
			total_length += ft_strlen(iterator->current->data);
		else if (iterator->current->data_type == T_TYPE_CHAR)
			total_length += 1;
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
	str = ft_calloc(sizeof (char)
			* ft_compute_join_length(iterator, delimiter));
	iterator->reset(iterator);
	while (iterator->current)
	{
		if (iterator->current->data_type == T_TYPE_STRING)
			ft_string_append(str, iterator->next_str(iterator));
		else if (iterator->current->data_type == T_TYPE_CHAR)
			ft_string_append_char(str, iterator->next_char(iterator));
		ft_string_append(str, delimiter);
	}
	iterator->free(iterator);
	return (str);
}
