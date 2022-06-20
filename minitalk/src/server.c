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
#include "libft/io/ft_io.h"
#include "libft/logic/ft_logic.h"
#include "libft/map/ft_map.h"
#include "libft/buffer/ft_buffer.h"
#include "libft/memory/ft_memory.h"

typedef struct t_network_message
{
	size_t		expected_size_bit;
	t_buffer	*data;

} t_network_message;

t_network_message *new_network_message()
{
	t_network_message *msg = ft_safe_malloc(sizeof(t_network_message));

	msg->expected_size_bit = 0;
	msg->data = new_buffer();
	return (msg);
}

t_map	*clients;

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	//ft_printfl("%d => %d, %d", signum, signum == SIGUSR1 ? false : true, info->si_pid, context);
	t_bit received_bit = signum == SIGUSR1 ? false : true;
	t_typed_ptr *ptr = ft_lld(info->si_pid);
	if (!clients->get(clients, ptr))
	{
		clients->add(clients, ptr->clone(ptr), new_typed_ptr(T_TYPE_UNKNOWN, new_network_message()));
	}
	t_network_message *msg = clients->get(clients, ptr)->value;
	msg->data->write_bit(msg->data, received_bit);
	//ft_printfl("buff: %s{.free()} (%d)", msg->data->to_str(msg->data), msg->data->index);
	if (msg->expected_size_bit == 0 && msg->data->index == sizeof(long) * 8)
	{
		msg->data->index = 0;
		msg->expected_size_bit = *msg->data->read(msg->data, T_TYPE_LONG)->as_long;
		msg->data->index = 0;
//		ft_printfl("expecting a message from %d of size %l", info->si_pid, msg->expected_size_bit);
		msg->data->free(msg->data);
		msg->data = new_buffer();
	}
	if (msg->expected_size_bit > 0 && msg->data->index == msg->expected_size_bit)
	{
//		ft_printfl("\nreceived complete: %s{.free()} (%d)", msg->data->to_str(msg->data), msg->data->size_bits);
		msg->data->index = 0;
		t_typed_ptr *p = msg->data->read(msg->data, T_TYPE_MAP);
		ft_printfl("%s{.free()}", p->to_str(p));
	}
	usleep(200);
	if (info->si_pid) kill(info->si_pid, SIGUSR2);
//
//
//	ptr->free(ptr);
	ft_printf("", received_bit, info, context);
}

int	main(int argc, t_string *argv)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	clients = new_map();
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printfl("server PID: %d", getpid());
	while (true)
		pause();
	ft_printfl("", argv, argc);
}
