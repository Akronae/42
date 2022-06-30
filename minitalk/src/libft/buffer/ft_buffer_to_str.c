/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "../memory/ft_memory.h"

t_str ft_buffer_to_str(t_buffer *buff)
{
	t_str str = ft_safe_malloc(buff->size_bits + 1);
	size_t	bit_index = 0;

	while (bit_index < buff->used_bits)
	{
		str[bit_index] = buff->get_bit(buff, bit_index) + '0';
		bit_index++;
	}
	return (str);
}