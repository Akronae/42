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

//	buff->data = new_list();
	buff->data_s = NULL;
	buff->size_bits = 0;
	buff->index = 0;
	buff->free = ft_buffer_free;
	buff->get_bit = ft_buffer_get_bit;
	buff->read = ft_buffer_read;
	buff->read_bit = ft_buffer_read_bit;
	buff->read_byte = ft_buffer_read_byte;
	buff->set_bit = ft_buffer_set_bit;
	buff->to_str = ft_buffer_to_str;
	buff->write = ft_buffer_write;
	buff->write_bit = ft_buffer_write_bit;
	buff->write_byte = ft_buffer_write_byte;
	return (buff);
}