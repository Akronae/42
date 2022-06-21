/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ipc_socket.c                                   :+:      :+:    :+:   */
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

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	usleep(200);
	ft_printf("", signum, info->si_pid, info, context);
}

t_ipc_socket *new_ipc_socket(int pid, void (*signal_handler)(int signum, siginfo_t *info, void *context))
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = ft_signal_handler;
	if (signal_handler)
		sa_signal.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);

	t_ipc_socket *sock = ft_safe_malloc(sizeof(t_ipc_socket));
	sock->pid = pid;
	sock->send = ft_ipc_socket_send;
	sock->free = ft_ipc_socket_free;

	return (sock);
}
