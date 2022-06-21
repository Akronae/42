/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_write_key_value_pair.c                   :+:      :+:    :+:   */
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

void	ft_buffer_write_key_value_pair(t_buffer *self, t_key_value_pair *pair)
{
	self->write_typed_ptr(self, pair->key);
	self->write_typed_ptr(self, pair->value);
}
