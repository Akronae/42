/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_get_bit.c                         :+:      :+:    :+:   */
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

t_bool	ft_buffer_get_bit(t_buffer *buff, size_t bit_index)
{
	size_t	byte_index = bit_index / 8;
//	if (buff->data->length < byte_index + 1)
//		return (false);
	if (buff->size_bits < byte_index + 1)
		return (false);
//	t_typed_ptr *buffer_byte = buff->data->get_elem(buff->data, byte_index)->data;
//	return ft_binary_get_bit(*buffer_byte->as_str, bit_index % 8);
	return ft_binary_get_bit(buff->data_s[byte_index], bit_index % 8);
}