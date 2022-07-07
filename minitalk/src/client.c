/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
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
#include "libft/message/ft_message.h"
#include "libft/ipc_socket/ft_ipc_socket.h"

void	fta(int signum, siginfo_t *info, void *context)
{
	usleep(200);
	ft_unused("", signum, info, context);
}

int	main(int argc, t_str *argv)
{
	int				pid;
	t_ipc_socket	*sock;
	t_message		*msg;

	if (argc <= 2)
		ft_exit_err("usage:\n\t%s <SERVER PID> <MESSAGE>", argv[0]);
	pid = ft_str_to_number(argv[1]);
	ft_printfl("client PID: %d", getpid());
	sock = new_ipc_socket(pid);
	msg = new_message();
	msg->fields->add(msg->fields, ft_s("content"), ft_s(argv[2]));
	sock->send(sock, msg);
	msg->free(msg);
	sock->free(sock);
}
