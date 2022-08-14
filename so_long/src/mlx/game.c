/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "game_object.h"
#include "../libft/memory/ft_memory.h"
#include "../libft/io/ft_io.h"

void ft_game_render(t_game *self)
{
	self->tick++;

	t_mlx_client *client = self->window->client;
	t_mlx_img *canvas = client->img_empty(client, new_vector_2(1000, 500));
	t_iterator *i = self->scene->game_objects->get_iterator(self->scene->game_objects);

	while (i->next(i))
	{
		t_game_object *o = i->curr->data->value;
		if (o->on_update)
			o->on_update(o, self);
		o->render_to_img(o, canvas);
	}
	self->window->put_img(self->window, canvas, new_vector_2(0, 0));
}


int	ft_game_on_key_pressed_handler(t_mlx_window *window, int key, t_game *game)
{
	if (game->on_key_pressed)
		game->on_key_pressed(game, key);
	game->render(game);
}

int	ft_game_on_btn_close_pressed_handler(t_mlx_window *window, t_game *game)
{
	if (game->on_btn_close_pressed)
		game->on_btn_close_pressed(game);
	game->render(game);
}

int	ft_game_on_expose_handler(t_mlx_window *window, t_game *game)
{
	game->render(game);
}

void	ft_game_start(t_game *self)
{
	self->mlx_client->listen_for_input(self->mlx_client);
}

t_game *new_game()
{
	t_game *g = ft_safe_malloc(sizeof(t_game));

	g->mlx_client = new_mlx_client();
	g->tick = 0;
	g->start = ft_game_start;
	g->render = ft_game_render;
	g->scene = new_scene();
	g->window = g->mlx_client->new_window(g->mlx_client, new_vector_2(1000, 500), "New Game");
	g->window->on_expose = &ft_game_on_expose_handler;
	g->window->on_expose_arg = g;
	g->window->on_key_pressed = &ft_game_on_key_pressed_handler;
	g->window->on_key_pressed_arg = g;
	g->window->on_btn_close_pressed = &ft_game_on_btn_close_pressed_handler;
	g->window->on_btn_close_pressed_arg = g;
	
	return (g);
}
