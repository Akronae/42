/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../map/ft_map.h"
#include "../message/ft_message.h"
#include "../ipc_socket/ft_ipc_socket.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_typed_ptr_free(t_typed_ptr *self)
{
	if (self->value)
	{
		if (self->type == T_TYPE_LIST)
			((t_list *)self->value)->free(self->value);
		else if (self->type == T_TYPE_KV_PAIR)
			((t_kv_pair *)self->value)->free(self->value);
		else if (self->type == T_TYPE_MAP)
			((t_map *)self->value)->free(self->value);
		else if (self->type == T_TYPE_MESSAGE)
			((t_message *)self->value)->free(self->value);
		else if (self->type == T_TYPE_IPC_SOCKET)
			((t_ipc_socket *)self->value)->free(self->value);
		else if (self->type == T_TYPE_LONG || self->type == T_TYPE_STRING
			|| self->type == T_TYPE_CHAR || self->type == T_TYPE_INT
			|| self->type == T_TYPE_LLONG || self->type == T_TYPE_UNKNOWN)
			ft_safe_free(self->value);
		else
			ft_exit_err("does not know how to free type %d", self->type);
	}
	ft_safe_free(self);
}
