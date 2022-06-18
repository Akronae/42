/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_write.c                                  :+:      :+:    :+:   */
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

void	ft_buffer_write_bytes(t_buffer *self, void *bytes, size_t len_bytes)
{
	size_t i = 0;
	t_byte	*bytes_data = (t_byte*) bytes;

	while (i < len_bytes)
	{
		self->write_byte(self, bytes_data[i]);
		i++;
	}
}

void	ft_buffer_write_char(t_buffer *self, char data)
{
	ft_buffer_write_bytes(self, &data, sizeof(char));
}

void	ft_buffer_write_int(t_buffer *self, int data)
{
	ft_buffer_write_bytes(self, &data, sizeof(int));
}

void	ft_buffer_write_long(t_buffer *self, long data)
{
	ft_buffer_write_bytes(self, &data, sizeof(long));
}

void	ft_buffer_write_llong(t_buffer *self, long long data)
{
	ft_buffer_write_bytes(self, &data, sizeof(long long));
}

void	ft_buffer_write_str(t_buffer *self, t_string str)
{
	ft_buffer_write_long(self, ft_strlen(str));
	ft_buffer_write_bytes(self, str, sizeof(char) * ft_strlen(str));
}

void	ft_buffer_write_typed_ptr(t_buffer *self, t_typed_ptr *data)
{
	ft_buffer_write_char(self, data->type);
	ft_buffer_write(self, data);
}

void	ft_buffer_write_list(t_buffer *self, t_list *list)
{
	ft_buffer_write_long(self, list->length);
	t_iterator *i = list->get_iterator(list);
	while (i->next(i))
	{
		ft_buffer_write_typed_ptr(self, i->curr->data);
	}
	i->free(i);
}

void	ft_buffer_write_key_value_pair(t_buffer *self, t_key_value_pair *pair)
{
	ft_buffer_write_typed_ptr(self, pair->key);
	ft_buffer_write_typed_ptr(self, pair->value);
}

void	ft_buffer_write_map(t_buffer *self, t_map *map)
{
	ft_buffer_write_list(self, map->entries);
}

void	ft_buffer_write(t_buffer *self, t_typed_ptr *data)
{
	if (data->type == T_TYPE_CHAR)
		ft_buffer_write_char(self, *data->as_str);
	else if (data->type == T_TYPE_LONG)
		ft_buffer_write_long(self, *data->as_long);
	else if (data->type == T_TYPE_LLONG)
		ft_buffer_write_llong(self, *data->as_llong);
	else if (data->type == T_TYPE_STRING)
		ft_buffer_write_str(self, data->as_str);
	else if (data->type == T_TYPE_TYPED_PTR)
		ft_buffer_write_typed_ptr(self, data->value);
	else if (data->type == T_TYPE_LIST)
		ft_buffer_write_list(self, data->value);
	else if (data->type == T_TYPE_MAP)
		ft_buffer_write_map(self, data->value);
	else if (data->type == T_TYPE_KEY_VALUE_PAIR)
		ft_buffer_write_key_value_pair(self, data->value);
	else
		ft_exit_err("ft_buffer_write: cannot write type %d", data->type);
}