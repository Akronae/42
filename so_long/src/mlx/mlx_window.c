/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_window.h"
#include "vector.h"
#include "../libft/libft.h"
#include "../libft/io/ft_io.h"
#include "../libft/memory/ft_memory.h"
#include "../minilibx-linux/mlx.h"
#include "keysymdef.h"
#include <stdlib.h>
#include <X11/X.h>

void mlx_window_put_img(t_mlx_window *self, t_mlx_img *img, t_vector pos)
{
	mlx_put_image_to_window(self->client->addr, self->addr, img->addr, pos.x, pos.y);
}

int mlx_window_on_key_release_handler(int key, t_mlx_window *window)
{
	window->keys_pressed[key] = false;
	if (window->on_key_released)
		window->on_key_released(window, key, window->on_key_released_arg);

}

int mlx_window_on_key_pressed_handler(int key, t_mlx_window *window)
{
	window->keys_pressed[key] = true;
	if (window->on_key_pressed)
		window->on_key_pressed(window, key, window->on_key_pressed_arg);
}

int mlx_window_close_btn_pressed_handler(t_mlx_window *window)
{
	if (window->on_btn_close_pressed)
		window->on_btn_close_pressed(window, window->on_btn_close_pressed_arg);
}

int mlx_window_expose_handler(t_mlx_window *window)
{
	if (window->on_expose)
		window->on_expose(window, window->on_expose_arg);
}

t_mlx_window	*new_mlx_window(t_mlx_client *client, t_vector size, t_str title)
{
	t_mlx_window	*w = ft_safe_malloc(sizeof(t_mlx_window));

	w->client = client;
	w->size = size;
	w->addr = mlx_new_window(client->addr, size.x, size.y, title);
	w->key_down = false;
	w->put_img = &mlx_window_put_img;
	mlx_do_key_autorepeaton(client->addr);
	mlx_hook(w->addr, DestroyNotify, ButtonPressMask, &mlx_window_close_btn_pressed_handler, w);
	mlx_hook(w->addr, KeyPress, KeyPressMask, &mlx_window_on_key_pressed_handler, w);
	mlx_hook(w->addr, KeyRelease, KeyReleaseMask, &mlx_window_on_key_release_handler, w);
	mlx_expose_hook(w->addr, mlx_window_expose_handler, w);
	if (!w->addr)
		ft_exit_err("could not create new mlx window.");
	return (w);
}
