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

void	*ft_buffer_read_bytes(t_buffer *self, size_t len_bytes)
{
	size_t i = 0;
	t_byte *data = ft_safe_malloc(len_bytes);

	while (i < len_bytes)
	{
		*(data + i) = self->read_byte(self);
		i++;
	}
	return data;
}

long long	ft_buffer_read_number(t_buffer *self, int bytes_len)
{
	long long data = 0;
	t_byte *buff = ft_buffer_read_bytes(self, bytes_len);
	ft_memcpy(&data, buff, bytes_len);
	ft_safe_free(buff);
	return (data);
}

char	ft_buffer_read_char(t_buffer *self)
{
	return (ft_buffer_read_number(self, sizeof (char)));
}

char	ft_buffer_read_int(t_buffer *self)
{
	return (ft_buffer_read_number(self, sizeof (int)));
}

long	ft_buffer_read_long(t_buffer *self)
{
	return (ft_buffer_read_number(self, sizeof (long)));
}

long long	ft_buffer_read_llong(t_buffer *self)
{
	return (ft_buffer_read_number(self, sizeof (long long)));
}

t_string ft_buffer_read_str(t_buffer *self)
{
	long len = ft_buffer_read_long(self);
	t_string data = ft_buffer_read_bytes(self, len);
	t_string str = ft_safe_malloc(len + 1);
	ft_memcpy(str, data, len);
	ft_safe_free(data);
	return str;
}

t_typed_ptr	*ft_buffer_read_typed_ptr(t_buffer *self)
{
	t_type type = (t_type) ft_buffer_read_char(self);
	return ft_buffer_read(self, type);
}

t_list	*ft_buffer_read_list(t_buffer *self)
{
	long len = ft_buffer_read_long(self);
	t_list *list = new_list();
	while (len)
	{
		list->push_data(list, ft_buffer_read_typed_ptr(self));
		len--;
	}
	return (list);
}

t_key_value_pair	*ft_buffer_read_key_value_pair(t_buffer *self)
{
	t_typed_ptr *key = ft_buffer_read_typed_ptr(self);
	t_typed_ptr *value = ft_buffer_read_typed_ptr(self);
	return (new_key_value_pair(key, value));
}

t_map	*ft_buffer_read_map(t_buffer *self)
{
	t_map *map = new_map();
	map->entries->free(map->entries);
	map->entries = ft_buffer_read_list(self);
	return (map);
}

t_typed_ptr *ft_buffer_read(t_buffer *self, t_type type)
{
	if (type == T_TYPE_CHAR)
		return new_typed_ptr(T_TYPE_CHAR, ft_char_to_str(ft_buffer_read_char(self)));
	else if (type == T_TYPE_LONG)
		return new_typed_ptr_llong(ft_buffer_read_long(self));
	else if (type == T_TYPE_LLONG)
		return new_typed_ptr_llong(ft_buffer_read_llong(self));
	else if (type == T_TYPE_STRING)
		return new_typed_ptr_str(ft_buffer_read_str(self));
	else if (type == T_TYPE_TYPED_PTR)
		return new_typed_ptr(T_TYPE_TYPED_PTR, ft_buffer_read_typed_ptr(self));
	else if (type == T_TYPE_LIST)
		return new_typed_ptr(T_TYPE_LIST, ft_buffer_read_list(self));
	else if (type == T_TYPE_KEY_VALUE_PAIR)
		return new_typed_ptr(T_TYPE_KEY_VALUE_PAIR, ft_buffer_read_key_value_pair(self));
	else if (type == T_TYPE_MAP)
		return new_typed_ptr(T_TYPE_MAP, ft_buffer_read_map(self));
	else
		ft_exit_err("ft_buffer_read: cannot read type %d", type);
	return NULL;
}
