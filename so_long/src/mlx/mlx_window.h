/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "vector.h"
# include "mlx_img.h"
# include "mlx_client.h"
# include "../libft/libft.h"
# include "../libft/string/ft_string.h"

typedef struct t_mlx_window
{
	struct t_mlx_client	*client;
	t_vector		size;
	void			*addr;
	t_bool			key_down;
	t_bool			keys_pressed[0xffff];
	void			(*put_img)(struct t_mlx_window *self, struct t_mlx_img *img, t_vector pos);
	int				(*on_btn_close_pressed)(struct t_mlx_window *self, void *arg);
	void			*on_btn_close_pressed_arg;
	int				(*on_key_pressed)(struct t_mlx_window *self, int keycode, void *arg);
	void			*on_key_pressed_arg;
	int				(*on_key_released)(struct t_mlx_window *self, int keycode, void *arg);
	void			*on_key_released_arg;
	int				(*on_expose)(struct t_mlx_window *self, void *arg);
	void			*on_expose_arg;
}	t_mlx_window;

void			mlx_window_put_img(t_mlx_window *self, struct t_mlx_img *img, t_vector pos);
int 			mlx_window_on_key_release_handler(int key, t_mlx_window *window);
int 			mlx_window_on_key_pressed_handler(int key, t_mlx_window *window);
int 			mlx_window_close_btn_pressed_handler(t_mlx_window *window);
int 			mlx_window_expose_handler(t_mlx_window *window);
t_mlx_window	*new_mlx_window(struct t_mlx_client *client, t_vector size, t_str title);

#endif