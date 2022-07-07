/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:24:08 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"
#include "../memory/ft_memory.h"

t_message	*new_message(void)
{
	t_message	*msg;

	msg = ft_safe_malloc(sizeof(t_message));
	msg->expected_size_bit = -1;
	msg->data = new_buffer();
	msg->fields = new_map();
	msg->receive_bit = ft_message_receive_bit;
	msg->serialize = ft_message_serialize;
	msg->deserialize = ft_message_deserialize;
	msg->free = ft_message_free;
	return (msg);
}
