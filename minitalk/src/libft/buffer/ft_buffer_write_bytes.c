/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_write_bytes.c                            :+:      :+:    :+:   */
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
#include "../map/ft_map.h"

void	ft_buffer_write_bytes(t_buffer *self, void *bytes, size_t len_bytes)
{
	size_t i = 0;
	t_byte	*bytes_data = (t_byte*) bytes;

	while (i < len_bytes)
	{
		self->write_byte(self, bytes_data[i]);
		i++;
	}
}
