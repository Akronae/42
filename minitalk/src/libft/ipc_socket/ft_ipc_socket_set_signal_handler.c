/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipc_socket_set_signal_handler.c                 :+:      :+:    :+:   */
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

void	ft_ipc_socket_set_signal_handler(t_ipc_socket *self, void (*handler)(int signum, siginfo_t *info, void *context))
{
	if (!self->sigaction)
	{
		struct sigaction	*sa_signal = ft_safe_malloc(sizeof (struct sigaction));
		sigset_t			block_mask;

		sigemptyset(&block_mask);
//		sigaddset(&block_mask, SIGINT);
		sigaddset(&block_mask, SIGQUIT);
		sa_signal->sa_handler = 0;
		sa_signal->sa_flags = SA_SIGINFO;
		sa_signal->sa_mask = block_mask;
		self->sigaction = sa_signal;
	}

	self->sigaction->sa_sigaction = handler;
	sigaction(SIGINT, self->sigaction, NULL);
//	sigaction(SIGSEGV, self->sigaction, NULL);
	sigaction(SIGTERM, self->sigaction, NULL);
//	sigaction(SIGQUIT, self->sigaction, NULL);
	sigaction(SIGUSR1, self->sigaction, NULL);
	sigaction(SIGUSR2, self->sigaction, NULL);
}
