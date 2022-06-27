/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_receive_bit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:24:08 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"
#include <stdlib.h>

void	ft_message_receive_bit(t_message *self, t_bit bit)
{
	self->data->write_bit(self->data, bit);
	if (self->expected_size_bit == -1 && self->data->index_write >= sizeof(self->expected_size_bit) * 8)
	{
		self->expected_size_bit = self->data->read_long(self->data);
	}
	if (self->expected_size_bit > 0 && self->data->index_write >= (size_t) self->expected_size_bit)
	{
		// TODO: Move in deserialize method
		self->fields->free(self->fields);
		self->fields = self->data->read_map(self->data);
		self->is_complete = true;
	}
}
