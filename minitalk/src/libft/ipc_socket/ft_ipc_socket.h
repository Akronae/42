/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipc_socket.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IPC_SOCKET_H
# define FT_IPC_SOCKET_H

#include <signal.h>
# include "unistd.h"
# include "../libft.h"
# include "../map/ft_map.h"
# include "../buffer/ft_buffer.h"
# include "../logic/ft_logic.h"
# include "../message/ft_message.h"

typedef struct t_ipc_socket
{
	int pid;
	struct sigaction *sigaction;
	t_bool	 is_listening;
	void	(*send)(struct t_ipc_socket *self, t_message *message);
	void	(*free)(struct t_ipc_socket *self);
	void	(*listen)(struct t_ipc_socket *self);
	void	(*on_message_received)(struct t_ipc_socket *self, struct t_ipc_socket *from, t_message *message);
	void	(*set_signal_handler)(struct t_ipc_socket *self, void (*handler)(int signum, siginfo_t *info, void *context));
} t_ipc_socket;

t_ipc_socket *new_ipc_socket(int pid);
void	ft_ipc_socket_send(t_ipc_socket *self, t_message *message);
void	ft_ipc_socket_set_signal_handler(t_ipc_socket *self, void (*handler)(int signum, siginfo_t *info, void *context));
void	ft_ipc_socket_free(t_ipc_socket *self);
void	ft_ipc_socket_listen(t_ipc_socket *self);
void	ft_signal_handler(int signum, siginfo_t *info, void *context);

#endif
