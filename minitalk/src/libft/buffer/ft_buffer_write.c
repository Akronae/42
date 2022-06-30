/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../map/ft_map.h"

void	ft_buffer_write(t_buffer *self, t_typed_ptr *data)
{
	if (data->type == T_TYPE_CHAR)
		self->write_char(self, *data->as_str);
	else if (data->type == T_TYPE_LONG)
		self->write_long(self, *data->as_long);
	else if (data->type == T_TYPE_LLONG)
		self->write_llong(self, *data->as_llong);
	else if (data->type == T_TYPE_STRING)
		self->write_str(self, data->as_str);
	else if (data->type == T_TYPE_TYPED_PTR)
		self->write_typed_ptr(self, data->value);
	else if (data->type == T_TYPE_LIST)
		self->write_list(self, data->value);
	else if (data->type == T_TYPE_MAP)
		self->write_map(self, data->value);
	else if (data->type == T_TYPE_KEY_VALUE_PAIR)
		self->write_key_value_pair(self, data->value);
	else
		ft_exit_err("ft_buffer_write: cannot write type %d", data->type);
}