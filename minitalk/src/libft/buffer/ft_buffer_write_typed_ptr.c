/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_write_typed_ptr.c                        :+:      :+:    :+:   */
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

void	ft_buffer_write_typed_ptr(t_buffer *self, t_typed_ptr *data)
{
	self->write_char(self, data->type);
	self->write(self, data);
}
