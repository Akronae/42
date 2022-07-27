/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "libft/io/ft_io.h"
#include "libft/logic/ft_logic.h"
#include "libft/map/ft_map.h"
#include "libft/buffer/ft_buffer.h"
#include "libft/memory/ft_memory.h"
#include "libft/message/ft_message.h"
#include "libft/ipc_socket/ft_ipc_socket.h"
#include "minilibx-linux/mlx.h"

int	main(int argc, t_str *argv)
{
	void *mlx_id = mlx_init();
	mlx_new_window(mlx_id, 100, 100, "lalalal!");
	ft_printfl("heeeeey!");
	ft_unused("", argc, argv);
	while (true) {}
}
