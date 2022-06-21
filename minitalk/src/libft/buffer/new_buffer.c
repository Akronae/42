/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "../memory/ft_memory.h"

t_buffer	*new_buffer()
{
	t_buffer *buff = ft_safe_malloc(sizeof(t_buffer));

	buff->data = NULL;
	buff->size_bits = 0;
	buff->index_write = 0;
	buff->index_read = 0;
	buff->free = ft_buffer_free;
	buff->get_bit = ft_buffer_get_bit;
	buff->read = ft_buffer_read;
	buff->read_bit = ft_buffer_read_bit;
	buff->read_byte = ft_buffer_read_byte;
	buff->read_bytes = ft_buffer_read_bytes;
	buff->read_char = ft_buffer_read_char;
	buff->read_int = ft_buffer_read_int;
	buff->read_key_value_pair = ft_buffer_read_key_value_pair;
	buff->read_list = ft_buffer_read_list;
	buff->read_llong = ft_buffer_read_llong;
	buff->read_long = ft_buffer_read_long;
	buff->read_map = ft_buffer_read_map;
	buff->read_number = ft_buffer_read_number;
	buff->read_str = ft_buffer_read_str;
	buff->read_typed_ptr = ft_buffer_read_typed_ptr;
	buff->write_char = ft_buffer_write_char;
	buff->write_int = ft_buffer_write_int;
	buff->write_key_value_pair = ft_buffer_write_key_value_pair;
	buff->write_list = ft_buffer_write_list;
	buff->write_llong = ft_buffer_write_llong;
	buff->write_long = ft_buffer_write_long;
	buff->write_map = ft_buffer_write_map;
	buff->write_str = ft_buffer_write_str;
	buff->write_typed_ptr = ft_buffer_write_typed_ptr;
	buff->set_bit = ft_buffer_set_bit;
	buff->to_str = ft_buffer_to_str;
	buff->write = ft_buffer_write;
	buff->write_bit = ft_buffer_write_bit;
	buff->write_byte = ft_buffer_write_byte;
	buff->write_bytes = ft_buffer_write_bytes;
	return (buff);
}