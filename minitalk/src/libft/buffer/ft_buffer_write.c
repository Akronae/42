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

void	ft_buffer_write_mem(t_buffer *self, void *bytes, size_t len_bytes)
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
	ft_buffer_write_mem(self, &data, sizeof(char));
}

void	ft_buffer_write_long(t_buffer *self, long data)
{
	ft_buffer_write_mem(self, &data, sizeof(long));
}

void	ft_buffer_write_llong(t_buffer *self, long long data)
{
	ft_buffer_write_mem(self, &data, sizeof(long long));
}

void	ft_buffer_write_str(t_buffer *self, t_string str)
{
	ft_buffer_write_long(self, ft_strlen(str));
	ft_buffer_write_mem(self, str, sizeof(char) * ft_strlen(str));
}

void	ft_buffer_write_typed_ptr(t_buffer *self, t_typed_ptr *data)
{
	ft_buffer_write_char(self, data->type);
	ft_buffer_write(self, data);
}

void	ft_buffer_write(t_buffer *self, t_typed_ptr *data)
{
	if (data->type == T_TYPE_LLONG)
		ft_buffer_write_llong(self, *data->as_llong);
	else if (data->type == T_TYPE_STRING)
		ft_buffer_write_str(self, data->as_str);
	else if (data->type == T_TYPE_TYPED_PTR)
		ft_buffer_write_typed_ptr(self, data->value);
	else
		ft_exit_err("ft_buffer_read: cannot write type %d", data->type);
}