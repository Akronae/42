/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include "libft/libft.h"
#include "libft/io/ft_io.h"
#include "libft/logic/ft_logic.h"
#include "libft/map/ft_map.h"
#include "libft/buffer/ft_buffer.h"
#include "libft/memory/ft_memory.h"
#include "libft/message/ft_message.h"
#include "libft/ipc_socket/ft_ipc_socket.h"

t_map	*clients;

void	ft_on_message_received(int from_pid, t_message *message)
{
	ft_printfl("[%d]: %s", from_pid, message->fields->get(message->fields, ft_s("message"))->as_str);
}

void	ft_server_signal_handler(int signum, siginfo_t *info, void *context)
{
	t_bit received_bit = signum == SIGUSR1 ? false : true;
	t_typed_ptr *ptr = ft_lld(info->si_pid);
	if (!clients->get(clients, ptr))
	{
		clients->add(clients, ptr->clone(ptr), new_typed_ptr(T_TYPE_UNKNOWN, new_message()));
	}
	t_message *msg = clients->get(clients, ptr)->value;
	ft_message_receive_bit(msg, received_bit);
	if (msg->is_complete)
		ft_on_message_received(info->si_pid, msg);

	usleep(200);
	if (info->si_pid) kill(info->si_pid, SIGUSR2);
	ft_printf("", received_bit, info, context);
}

int	main(int argc, t_string *argv)
{
	clients = new_map();
	t_ipc_socket *sock = new_ipc_socket(-1, ft_server_signal_handler);
	ft_printfl("server PID: %d", getpid());
	while (true)
		pause();
	ft_printfl("", argv, argc, sock);
}
