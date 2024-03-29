/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_serialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:24:08 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

void	ft_message_serialize(t_message *self)
{
	t_buffer	*buff;

	buff = new_buffer();
	buff->write_map(buff, self->fields);
	self->data->write_llong(self->data, buff->used_bits
		+ sizeof(self->expected_size_bit) * BITS_IN_BYTE);
	self->data->write_buffer(self->data, buff);
	buff->free(buff);
}
