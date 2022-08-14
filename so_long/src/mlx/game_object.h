/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "vector.h"
# include "mlx_img.h"
# include "game.h"

typedef struct t_game_object
{
	t_vector	transform;
	t_mlx_img	*sprite;
	void		(*on_update)(struct t_game_object *self, struct t_game *game);
void			(*render_to_img)(struct t_game_object *self, t_mlx_img *img);
}	t_game_object;

void			ft_game_object_render_to_img(t_game_object *self, t_mlx_img *img);
t_game_object	*new_game_object();

#endif