/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_set_bit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../logic/ft_logic.h"
#include "ft_buffer.h"
#include "../binary/ft_binary.h"

void	ft_buffer_set_bit(t_buffer *buff, size_t bit_index, t_bool value)
{
	size_t	byte_index = bit_index / 8;
	while (buff->data->length < byte_index + 1)
		buff->data->push_char(buff->data, 0);
	t_typed_ptr *buffer_byte = buff->data->get_elem(buff->data, byte_index)->data;
	*buffer_byte->as_str = ft_binary_set_bit(*buffer_byte->as_str, bit_index % 8, value);
	buff->size_bits = buff->data->length * 8;
	buff->index = bit_index;
}