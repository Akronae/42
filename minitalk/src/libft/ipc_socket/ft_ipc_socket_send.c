/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipc_socket_send.c                               :+:      :+:    :+:   */
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
#include <stdio.h>

t_bool	g_should_abort_sending;
t_bool	g_received_last;

void	ft_acknowledgement_signal_handler(int signum, siginfo_t *info,
			void *context)
{
	if (signum == SIGTERM || signum == SIGINT)
	{
		ft_printfl("exiting...");
		g_should_abort_sending = true;
		return ;
	}
	usleep(200);
	g_received_last = true;
	ft_unused("", signum, info, context);
}

void	ft_send_signal(int to_pid, int sig)
{
	if (kill(to_pid, sig) != EXIT_SUCCESS)
	{
		ft_printfl("process with PID '%d' does not exist"
			" or cannot be reached.", to_pid);
		kill(getpid(), SIGTERM);
	}
}

void	ft_ipc_socket_send(t_ipc_socket *self, t_message *message)
{
	size_t	i;

	i = 0;
	message->serialize(message);
	self->set_signal_handler(self, ft_acknowledgement_signal_handler);
	g_should_abort_sending = false;
	while (i < message->data->used_bits)
	{
		if (i > 0)
			ft_printf("\b\r");
		ft_printfl("[client] sending to '%d', progress: %d%%..", self->pid,
			(int)(i * 1.0f / (message->data->used_bits - 1) * 100));
		if (message->data->get_bit(message->data, i))
			ft_send_signal(self->pid, SIGUSR2);
		else
			ft_send_signal(self->pid, SIGUSR1);
		if (g_should_abort_sending)
			break ;
		i++;
		while (!g_received_last)
		{
		}
		g_received_last = false;
	}
	ft_printfl("[client] done.");
}
