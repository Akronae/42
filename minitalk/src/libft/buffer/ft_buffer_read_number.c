/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_read_number.c                            :+:      :+:    :+:   */
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

long long	ft_buffer_read_number(t_buffer *self, int bytes_len)
{
	long long data = 0;
	t_byte *buff = self->read_bytes(self, bytes_len);
	ft_memcpy(&data, buff, bytes_len);
	ft_safe_free(buff);
	return (data);
}
