/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipc_socket_listen.c                             :+:      :+:    :+:   */
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

t_map	*g_client;

void	ft_clients_stop_listening(void)
{
	t_list			*sockets;
	t_iterator		*i;

	sockets = g_client->get_str(g_client, "sockets")->value;
	i = sockets->get_iterator(sockets);
	while (i->next(i))
		((t_ipc_socket *)i->curr->data->value)->is_listening = false;
	i->free(i);
}

void	ft_broadcast_received_message(t_message *message, int from_pid)
{
	t_list			*sockets;
	t_ipc_socket	*from_sock;
	t_iterator		*i;
	t_ipc_socket	*curr_sock;

	sockets = g_client->get_str(g_client, "sockets")->value;
	from_sock = new_ipc_socket(from_pid);
	i = sockets->get_iterator(sockets);
	while (i->next(i))
	{
		curr_sock = i->curr->data->value;
		if (curr_sock->on_message_received)
			curr_sock->on_message_received(curr_sock, from_sock, message);
	}
	i->free(i);
	from_sock->free(from_sock);
}

void	ft_receive_bit(t_bit received_bit, int from_pid)
{
	t_map		*messages_by_pid;
	t_message	*msg;
	t_list		*messages;

	messages_by_pid = g_client->get_str(g_client, "messages")->value;
	if (!messages_by_pid->get_lld(messages_by_pid, from_pid))
		messages_by_pid->add(messages_by_pid, ft_lld(from_pid),
			new_typed_ptr(T_TYPE_LIST, new_list()));
	messages = messages_by_pid->get_lld(messages_by_pid, from_pid)->value;
	if (messages->length == 0)
		messages->push_data(messages, new_typed_ptr(T_TYPE_MESSAGE,
				new_message()));
	msg = messages->get_elem(messages, -1)->data->value;
	ft_message_receive_bit(msg, received_bit);
	if (msg->is_complete)
		ft_broadcast_received_message(msg, from_pid);
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	t_bit	received_bit;

	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		if (signum == SIGTERM || signum == SIGINT)
			ft_printfl("[server] received exit signal, quitting...");
		else
			ft_printfl("[server] received forbidden signal %d, quitting...",
				signum);
		ft_clients_stop_listening();
		return ;
	}
	received_bit = ft_if_int(signum == SIGUSR1, false, true);
	ft_receive_bit(received_bit, info->si_pid);
	usleep(200);
	kill(info->si_pid, SIGUSR1);
	ft_unused("", received_bit, info, context);
}

void	ft_ipc_socket_listen(t_ipc_socket *self)
{
	t_list	*sockets;

	if (!g_client)
	{
		g_client = new_map();
		g_client->add(g_client, ft_s("sockets"),
			new_typed_ptr(T_TYPE_LIST, new_list()));
		g_client->add(g_client, ft_s("messages"),
			new_typed_ptr(T_TYPE_MAP, new_map()));
	}
	self->set_signal_handler(self, ft_signal_handler);
	sockets = g_client->get_str(g_client, "sockets")->value;
	sockets->push_data(sockets, new_typed_ptr(T_TYPE_IPC_SOCKET, self));
	self->is_listening = true;
	while (self->is_listening)
		pause();
	g_client->free(g_client);
}
