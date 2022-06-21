/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_io.h"
#include "libft/number/ft_number.h"
#include "libft/list/ft_list.h"
#include "libft/logic/ft_logic.h"
#include "libft/memory/ft_memory.h"
#include "libft/binary/ft_binary.h"
#include "libft/buffer/ft_buffer.h"
#include "libft/map/ft_map.h"
#include "libft/message/ft_message.h"
#include "libft/ipc_socket/ft_ipc_socket.h"


int	main(int argc, t_string *argv)
{
	if (argc <= 2)
		ft_exit_err("usage:\n\t%s <SERVER PID> <MESSAGE>", argv[0]);
	int pid = ft_str_to_number(argv[1]);
	ft_printfl("client PID: %d", getpid());

	t_ipc_socket *sock = new_ipc_socket(pid, NULL);
	t_message *msg = new_message();
	t_typed_ptr *p;
	p = ft_s("message");
	msg->fields->add(msg->fields, p, ft_s(argv[2]));
	sock->send(sock, msg);

	msg->free(msg);
	sock->free(sock);
}
