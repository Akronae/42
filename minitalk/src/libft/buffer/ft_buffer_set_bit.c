/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_set_bit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../logic/ft_logic.h"
#include "ft_buffer.h"
#include "../binary/ft_binary.h"
#include "../memory/ft_memory.h"
#include "../math/ft_math.h"
#include "../io/ft_io.h"

void	ft_buffer_set_bit(t_buffer *buff, size_t bit_index, t_bool value)
{
	size_t	byte_index;
	size_t	new_size;
	t_str	new;

	byte_index = bit_index / BITS_IN_BYTE;
	while (buff->size_bits / BITS_IN_BYTE < byte_index + 1)
	{
		new_size = ft_math_max(buff->size_bits / BITS_IN_BYTE * 2, 50);
		new = ft_safe_malloc(new_size);
		ft_memcpy(new, buff->data, buff->size_bits / BITS_IN_BYTE);
		ft_safe_free(buff->data);
		buff->data = new;
		buff->size_bits = new_size * BITS_IN_BYTE;
	}
	buff->data[byte_index] = ft_binary_set_bit(buff->data[byte_index],
			bit_index % BITS_IN_BYTE, value);
	buff->index_write = bit_index;
	buff->used_bits = bit_index + 1;
}
