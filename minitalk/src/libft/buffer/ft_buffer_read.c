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
	int i = 0;
	long long data = 0;
	while (i < bytes_len)
	{
		data += (self->read_byte(self) << ((i * 8) % 32));
		i += 1;
	}
	return (data);
}

char	ft_buffer_read_char(t_buffer *self)
{
	return (ft_buffer_read_number(self, sizeof (char)));
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

t_typed_ptr *ft_buffer_read(t_buffer *self, t_type type)
{
	if (type == T_TYPE_LLONG)
		return new_typed_ptr_llong(ft_buffer_read_llong(self));
	else if (type == T_TYPE_STRING)
		return new_typed_ptr_str(ft_buffer_read_str(self));
	else if (type == T_TYPE_TYPED_PTR)
		return ft_buffer_read_typed_ptr(self);
	else
		ft_exit_err("ft_buffer_read: cannot read type %d", type);
	return NULL;
}
