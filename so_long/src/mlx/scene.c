/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "../libft/memory/ft_memory.h"

void	ft_scene_add_game_object(t_scene *self, t_game_object *obj)
{
	self->game_objects->push_data(self->game_objects, new_typed_ptr(T_TYPE_UNKNOWN, obj));
}

t_scene	*new_scene()
{
	t_scene *s = ft_safe_malloc(sizeof(t_scene));

	s->game_objects = new_list();
	s->add_game_object = &ft_scene_add_game_object;
	return (s);
}
