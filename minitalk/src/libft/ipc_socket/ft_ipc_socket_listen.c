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

t_map *clients;

void	ft_clients_stop_listening(void)
{
	ft_printfl("stop listening!!!!!!!!!!!!!!!");
	t_list *sockets = clients->get_str(clients, "sockets")->value;
	t_iterator *i = sockets->get_iterator(sockets);
	while (i->next(i))
	{
		t_ipc_socket *s = i->curr->data->value;
		s->is_listening = false;
	}
	i->free(i);
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		ft_printfl("received not handled signum =================================> %d", signum);
		ft_clients_stop_listening();
		return ;
	}
	t_bit received_bit = signum == SIGUSR1 ? false : true;
	t_typed_ptr *ptr = ft_lld(info->si_pid);
	t_map *messages_by_pid = clients->get_str(clients, "messages")->value;
	if (!messages_by_pid->get(messages_by_pid, ptr))
		messages_by_pid->add(messages_by_pid, ft_lld(info->si_pid), new_typed_ptr(T_TYPE_LIST, new_list()));
	t_list *messages = messages_by_pid->get(messages_by_pid, ptr)->value;
	if (messages->length == 0)
		messages->push_data(messages, new_typed_ptr(T_TYPE_MESSAGE, new_message()));
	t_message *msg = messages->get_elem(messages, -1)->data->value;
	ft_message_receive_bit(msg, received_bit);
	if (msg->is_complete)
	{
		t_list *sockets = clients->get_str(clients, "sockets")->value;
		t_ipc_socket *from_sock = new_ipc_socket(info->si_pid);
		t_iterator *i = sockets->get_iterator(sockets);
		while (i->next(i))
		{
			t_ipc_socket *s = i->curr->data->value;
			if (s->on_message_received)
				s->on_message_received(s, from_sock, msg);
		}
		i->free(i);
		from_sock->free(from_sock);
	}
	ptr->free(ptr);
	usleep(200);
	kill(info->si_pid, SIGUSR1);
	ft_unused("", received_bit, info, context);
}

void	ft_ipc_socket_listen(t_ipc_socket *self)
{
	if (!clients)
	{
		clients = new_map();
		clients->add(clients, ft_s("sockets"), new_typed_ptr(T_TYPE_LIST, new_list()));
		clients->add(clients, ft_s("messages"), new_typed_ptr(T_TYPE_MAP, new_map()));
	}

	self->set_signal_handler(self, ft_signal_handler);
	t_list *sockets = clients->get_str(clients, "sockets")->value;
	sockets->push_data(sockets, new_typed_ptr(T_TYPE_IPC_SOCKET, self));
	self->is_listening = true;
	while (self->is_listening)
	{
		pause();
	}
	ft_printfl("laaalllllllllllllllllllllllllllllll");
//	t_list *m = clients->get_str(clients, "sockets")->value;
//	m->free(m);
//	t_map *mm = clients->get_str(clients, "messages")->value;
//	mm->free(mm);
	clients->free(clients);
}
