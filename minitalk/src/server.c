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

#include "minitalk.h"
#include "libft/libft.h"
#include "libft/io/ft_io.h"
#include "libft/logic/ft_logic.h"
#include "libft/map/ft_map.h"
#include "libft/buffer/ft_buffer.h"
#include "libft/memory/ft_memory.h"
#include "libft/message/ft_message.h"
#include "libft/ipc_socket/ft_ipc_socket.h"

void	ft_on_message_received(t_ipc_socket *self, t_ipc_socket *from, t_message *message)
{
	ft_printfl("[<yellow>%d</yellow>] %s", from->pid, message->fields->get_str(message->fields, "message")->as_str);
	ft_unused("", self);
}

int	main(int argc, t_str *argv)
{
	t_ipc_socket *sock = new_ipc_socket(-1);
	sock->on_message_received = ft_on_message_received;
	ft_printfl("server PID: <green>%d</green>", getpid());
	sock->listen(sock);
	ft_unused("", argv, argc, sock);
}
