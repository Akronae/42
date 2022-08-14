/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../libft/list/ft_list.h"
# include "game_object.h"

typedef struct t_scene
{
	t_list *game_objects;
	void	(*add_game_object)(struct t_scene *self, struct t_game_object *obj);
} t_scene;

t_scene	*new_scene();
void	ft_scene_add_game_object(t_scene *self, struct t_game_object *obj);

#endif