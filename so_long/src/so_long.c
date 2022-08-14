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
#include "libft/memory/ft_memory.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/X.h>
#include "mlx/game.h"
#include "mlx/keysymdef.h"
#include "brigitte.h"

int	on_btn_close_pressed(t_game *game)
{
	exit(0);
}

void	on_key_pressed(t_game *game, int key)
{
	if (key == XK_Escape)
		on_btn_close_pressed(game);
}

int	main(int argc, t_str *argv)
{
	t_game *game = new_game();

	game->on_btn_close_pressed = &on_btn_close_pressed;
	game->on_key_pressed = &on_key_pressed;
	game->scene->add_game_object(game->scene, new_brigitte(game));

	game->start(game);
	ft_unused("", argc, argv);
}
