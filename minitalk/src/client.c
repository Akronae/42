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

#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"
#include "libft/io/ft_io.h"
#include "libft/number/ft_number.h"
#include "libft/list/ft_list.h"
#include "libft/logic/ft_logic.h"
#include "libft/memory/ft_memory.h"
#include "libft/binary/ft_binary.h"
#include "libft/buffer/ft_buffer.h"

int	main(int argc, t_string *argv)
{
	if (argc <= 1)
		ft_exit_err("usage:\n\t%s <SERVER PID> <MESSAGE>", argv[0]);

	t_buffer *buff = new_buffer();
	buff->write(buff, new_typed_ptr(T_TYPE_TYPED_PTR, ft_s("bonjour")));
	ft_printfl("buff: %s{.free()} (%d)", buff->to_str(buff), buff->index);
	buff->index = 0;
	t_typed_ptr *read =  buff->read(buff, T_TYPE_TYPED_PTR);
	ft_printfl("buff: %s{.free()}", read->to_str(read));

	read->free(read);
	buff->free(buff);

//	kill(ft_str_to_number(argv[1]), SIGUSR2);
//	kill(ft_str_to_number(argv[1]), SIGUSR1);
}
