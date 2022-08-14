/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brigitte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brigitte.h"
#include "libft/libft.h"
#include "libft/io/ft_io.h"
#include "libft/math/ft_math.h"
#include "libft/memory/ft_memory.h"
#include "minilibx-linux/mlx.h"
#include "mlx/keysymdef.h"
#include <stdlib.h>
#include <X11/X.h>
#include "mlx/mlx_window.h"
#include "mlx/vector.h"
#include "mlx/game_object.h"
#include "mlx/game.h"

void ft_brigitte_on_update(t_game_object *self, t_game *game)
{
	t_mlx_window *win = game->window;
	t_vector direction = new_vector_2(0, 0);

	if (win->keys_pressed[XK_Up]) direction.y = -1;
	if (win->keys_pressed[XK_Down]) direction.y = 1;
	if (win->keys_pressed[XK_Left]) direction.x = -1;
	if (win->keys_pressed[XK_Right]) direction.x = 1;
	t_vector speed = new_vector_2(20, 20);
	self->transform = self->transform.add(self->transform, speed.mult(speed, direction));
	self->sprite->scale = ft_vector_add_scalar(new_vector_2(0.5, 0.5), ft_math_abs_double(ft_math_sin(game->tick / 5.0)) / 10);
	if (direction.x) self->sprite->scale.x = ft_math_abs_double(self->sprite->scale.x) * direction.x;
}

t_game_object 	*new_brigitte(t_game *game)
{
	t_game_object *brigitte = new_game_object();
	brigitte->sprite = game->mlx_client->img_from_file(game->mlx_client, "src/brigitte.xpm");
	brigitte->sprite->scale = new_vector_2(0.5, 0.5);
	brigitte->on_update = &ft_brigitte_on_update;
	return (brigitte);
}
