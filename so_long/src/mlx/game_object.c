/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_object.h"
#include "../libft/memory/ft_memory.h"

void	ft_game_object_render_to_img(t_game_object *self, t_mlx_img *img)
{
	if (self->sprite)
		img->draw_img(img, self->sprite, self->transform);
}

t_game_object *new_game_object()
{
	t_game_object *g = ft_safe_malloc(sizeof(t_game_object));

	g->transform = new_vector_3(0, 0, 0);
	g->sprite = NULL;
	g->render_to_img = &ft_game_object_render_to_img;
}
