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
#include "../char/ft_char.h"
#include "../number/ft_number.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"

static size_t	ft_compute_join_length(t_list *str_list)
{
	size_t	total_length;

	total_length = 1;
	while (str_list->i->next(str_list->i))
		total_length += ft_strlen(str_list->i->curr->as_str);
	return (total_length);
}

char	*ft_list_join(t_list *self, char *delimiter)
{
	char		*str;
	t_list		*str_list;

	str_list = new_list();
	while (self->i->next(self->i))
	{
		if (self->i->curr->data_type == T_TYPE_UNKNOWN)
			str_list->push_str(str_list, ft_strdup(T_TYPE_UNKNOWN_STR));
		else if (self->i->curr->data_type == T_TYPE_STRING)
			str_list->push_str(str_list, ft_strdup(self->i->curr->as_str));
		else if (self->i->curr->data_type == T_TYPE_CHAR)
			str_list->push_str(str_list, ft_char_to_str(*self->i->curr->as_str));
		else if (self->i->curr->data_type == T_TYPE_LONG)
			str_list->push_str(str_list, ft_number_to_str(*self->i->curr->as_long));
		else
			ft_exit_err(ft_strjoin("ft_list_join: cannot parse type ",
								   ft_number_to_str(self->i->curr->data_type)));
		if (self->i->curr->next)
			str_list->push_str(str_list, ft_strdup(delimiter));
	}
	str = ft_safe_malloc(sizeof (char) * ft_compute_join_length(str_list));
	while (str_list->i->next(str_list->i))
		ft_str_append(str, str_list->i->curr->as_str);
	str_list->free(str_list);
	return (str);
}
