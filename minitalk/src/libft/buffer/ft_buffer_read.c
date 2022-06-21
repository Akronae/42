/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../map/ft_map.h"

t_typed_ptr *ft_buffer_read(t_buffer *self, t_type type)
{
	if (type == T_TYPE_CHAR)
		return new_typed_ptr(T_TYPE_CHAR, ft_char_to_str(self->read_char(self)));
	else if (type == T_TYPE_LONG)
		return new_typed_ptr_llong(self->read_long(self));
	else if (type == T_TYPE_LLONG)
		return new_typed_ptr_llong(self->read_llong(self));
	else if (type == T_TYPE_STRING)
		return new_typed_ptr_str(self->read_str(self));
	else if (type == T_TYPE_TYPED_PTR)
		return new_typed_ptr(T_TYPE_TYPED_PTR, self->read_typed_ptr(self));
	else if (type == T_TYPE_LIST)
		return new_typed_ptr(T_TYPE_LIST, self->read_list(self));
	else if (type == T_TYPE_KEY_VALUE_PAIR)
		return new_typed_ptr(T_TYPE_KEY_VALUE_PAIR, self->read_key_value_pair(self));
	else if (type == T_TYPE_MAP)
		return new_typed_ptr(T_TYPE_MAP, self->read_map(self));
	else
		ft_exit_err("ft_buffer_read: cannot read type %d", type);
	return NULL;
}
