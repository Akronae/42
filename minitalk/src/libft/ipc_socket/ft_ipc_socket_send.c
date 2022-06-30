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

void	ft_acknowledgement_signal_handler(int signum, siginfo_t *info, void *context)
{
	usleep(200);
	ft_unused("", signum, info, context);
}

void	ft_ipc_socket_send(t_ipc_socket *self, t_message *message)
{
	size_t i = 0;
	message->serialize(message);
	self->set_signal_handler(self, ft_acknowledgement_signal_handler);
	while (i < message->data->used_bits)
	{
		if (message->data->get_bit(message->data, i))
			kill(self->pid, SIGUSR2);
		else
			kill(self->pid, SIGUSR1);
		i++;
		pause();
	}
}