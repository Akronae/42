/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ipc_socket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:24:08 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ipc_socket.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../map/ft_map.h"
#include <signal.h>


t_ipc_socket *new_ipc_socket(int pid)
{
	t_ipc_socket *sock = ft_safe_malloc(sizeof(t_ipc_socket));
	sock->pid = pid;
	sock->send = ft_ipc_socket_send;
	sock->is_listening = false;
	sock->set_signal_handler = ft_ipc_socket_set_signal_handler;
	sock->free = ft_ipc_socket_free;
	sock->listen = ft_ipc_socket_listen;
	sock->on_message_received = NULL;
	sock->sigaction = NULL;
	return (sock);
}
