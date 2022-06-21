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
	void	(*send)(struct t_ipc_socket *self, t_message *message);
	void	(*free)(struct t_ipc_socket *self);
} t_ipc_socket;

t_ipc_socket *new_ipc_socket(int pid, void (*signal_handler)(int signum, siginfo_t *info, void *context));
void	ft_ipc_socket_send(t_ipc_socket *self, t_message *message);
void	ft_ipc_socket_free(t_ipc_socket *self);

#endif
