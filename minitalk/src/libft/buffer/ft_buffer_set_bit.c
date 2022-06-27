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
#include "../memory/ft_memory.h"
#include "../math/ft_math.h"
#include "../io/ft_io.h"

void	ft_buffer_set_bit(t_buffer *buff, size_t bit_index, t_bool value)
{
	size_t	byte_index = bit_index / 8;
	while (buff->size_bits / 8 < byte_index + 1)
	{
		size_t new_size = ft_math_max(buff->size_bits / 8 * 2, 50);
		t_str new = ft_safe_malloc(new_size);
		ft_memcpy(new, buff->data, buff->size_bits / 8);
		ft_safe_free(buff->data);
		buff->data = new;
		buff->size_bits = new_size * 8;
	}
	buff->data[byte_index] = ft_binary_set_bit(buff->data[byte_index], bit_index % 8, value);
	buff->index_write = bit_index;
	buff->used_bits = bit_index + 1;
}