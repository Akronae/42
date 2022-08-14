/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx_client.h"
# include "mlx_window.h"
# include "scene.h"
# include "../libft/libft.h"

typedef struct t_game
{
	t_mlx_client	*mlx_client;
	t_mlx_window	*window;
	struct t_scene			*scene;
	t_ullong		tick;
	void			(*on_key_pressed)(struct t_game *self, int key);
	void			(*on_btn_close_pressed)(struct t_game *self);
	void			(*start)(struct t_game *self);
	void			(*listen_for_inputs)(struct t_game *self);
	void			(*render)(struct t_game *self);

} t_game;

void		ft_game_render(t_game *self);
void	ft_game_start(t_game *self);
t_game	*new_game();

#endif