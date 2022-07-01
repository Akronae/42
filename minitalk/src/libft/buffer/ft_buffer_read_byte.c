/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_read_bit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"

t_byte	ft_buffer_read_byte(t_buffer *self)
{
	t_byte	byte;
	size_t	i;

	byte = 0;
	i = 0;
	while (i < BITS_IN_BYTE)
	{
		byte = ft_binary_set_bit(byte, i, self->read_bit(self));
		i++;
	}
	return (byte);
}
