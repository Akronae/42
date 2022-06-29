/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipc_socket_listen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
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

t_map	*Clients;

void	ft_clients_stop_listening(void)
{
	t_list			*sockets;
	t_iterator		*i;

	sockets = Clients->get_str(Clients, "sockets")->value;
	i = sockets->get_iterator(sockets);
	while (i->next(i))
		((t_ipc_socket *)i->curr->data->value)->is_listening = false;
	i->free(i);
}

void ft_broadcast_received_message(t_message *message, int from_pid)
{
	t_list			*sockets;
	t_ipc_socket	*from_sock;
	t_iterator		*i;
	t_ipc_socket	*curr_sock;

	sockets = Clients->get_str(Clients, "sockets")->value;
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

void ft_receive_bit(t_bit received_bit, int from_pid)
{
	// TODO: map->get_lld
	t_typed_ptr	*ptr;
	t_map	*messages_by_pid;
	t_message	*msg;
	t_list	*messages;

	ptr = ft_lld(from_pid);
	messages_by_pid = Clients->get_str(Clients, "messages")->value;
	if (!messages_by_pid->get(messages_by_pid, ptr))
		messages_by_pid->add(messages_by_pid, ft_lld(from_pid),
			new_typed_ptr(T_TYPE_LIST, new_list()));
	messages = messages_by_pid->get(messages_by_pid, ptr)->value;
	if (messages->length == 0)
		messages->push_data(messages, new_typed_ptr(T_TYPE_MESSAGE,
					new_message()));
	msg = messages->get_elem(messages, -1)->data->value;
	ft_message_receive_bit(msg, received_bit);
	if (msg->is_complete)
		ft_broadcast_received_message(msg, from_pid);
	ptr->free(ptr);
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	t_bit	received_bit;

	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		if (signum == SIGTERM || signum == SIGINT)
			ft_printfl("[server] received exit signal, quitting...");
		else
			ft_printfl("[server] received forbidden signal %d, quitting...", signum);
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

	if (!Clients)
	{
		Clients = new_map();
		Clients->add(Clients, ft_s("sockets"), new_typed_ptr(T_TYPE_LIST, new_list()));
		Clients->add(Clients, ft_s("messages"), new_typed_ptr(T_TYPE_MAP, new_map()));
	}
	self->set_signal_handler(self, ft_signal_handler);
	sockets = Clients->get_str(Clients, "sockets")->value;
	sockets->push_data(sockets, new_typed_ptr(T_TYPE_IPC_SOCKET, self));
	self->is_listening = true;
	while (self->is_listening)
		pause();
	Clients->free(Clients);
}
