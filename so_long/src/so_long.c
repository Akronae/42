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
#include "keysymdef.h"
#include <stdlib.h>
#include <X11/X.h>

typedef struct t_color
{
	t_uchar a;
	t_uchar r;
	t_uchar g;
	t_uchar b;
}	t_color;

typedef struct t_vector
{
	float x;
	float y;
	float z;
	struct t_vector	(*add)(struct t_vector self, struct t_vector v2);
	struct t_vector	(*inverse)(struct t_vector self);
	struct t_vector	(*mult)(struct t_vector self, struct t_vector factor);
	struct t_vector	(*mult_scalar)(struct t_vector self, float factor);
	struct t_vector	(*divide)(struct t_vector self, struct t_vector factor);
	t_str				(*to_str)(struct t_vector self);
}	t_vector;

typedef struct t_mlx_client
{
	void *addr;
	struct t_mlx_window	*(*new_window)(struct t_mlx_client *self, t_vector size, t_str title);
	struct t_mlx_img 	*(*img_empty)(struct t_mlx_client *self, t_vector size);
	struct t_mlx_img 	*(*img_from_file)(struct t_mlx_client *self, t_str file_path);
	void 	(*listen_for_input)(struct t_mlx_client *self);
} t_mlx_client;

typedef struct t_mlx_img
{
	struct t_mlx_client	*client;
	char	*addr;
	char	*data;
	int		bits_per_pixel;
	int 	line_size;
	t_vector	size;
	t_bool	endian;
	void	(*draw_img)(struct t_mlx_img *self, struct t_mlx_img *to_draw, t_vector origin);
	t_color	(*get_pixel)(struct t_mlx_img *self, t_vector pos);
	void 	(*set_pixel)(struct t_mlx_img *self, t_vector pos, t_color pixel);
	struct t_mlx_img 	*(*resize)(struct t_mlx_img *self, t_vector new_size);
}	t_mlx_img;

typedef struct t_mlx_window
{
	t_mlx_client *client;
	t_vector size;
	void *addr;
	t_bool key_down;
	void (*put_img)(struct t_mlx_window *self, t_mlx_img *img, t_vector pos);
	int (*on_btn_close_pressed)(struct t_mlx_window *self);
	int (*on_key_pressed)(struct t_mlx_window *self, int keycode, void *arg);
	void *on_key_pressed_arg;
	int (*on_expose)(struct t_mlx_window *self, void *arg);
	void *on_expose_arg;
} t_mlx_window;

typedef struct t_game_object
{
	t_vector transform;
	t_mlx_img *sprite;
} t_game_object;

typedef struct t_scene
{
	t_list *game_objects;
} t_scene;

typedef struct t_game
{
	t_mlx_client *mlx_client;
	t_mlx_window *window;
	t_scene *curr_scene;
	t_ullong tick;
	void	(*on_key_pressed)(t_mlx_window *window, int key, struct t_game *game);
} t_game;

void mlx_window_put_img(t_mlx_window *self, t_mlx_img *img, t_vector pos)
{
	mlx_put_image_to_window(self->client->addr, self->addr, img->addr, pos.x, pos.y);
}

int mlx_window_on_key_down_handler(int key, t_mlx_window *window)
{
	ft_printfl("%d", key);
	window->key_down = true;
}

int mlx_window_on_key_up_handler(int key, t_mlx_window *window)
{
	window->key_down = false;
}

int mlx_window_close_btn_pressed_handler(t_mlx_window *window)
{
	if (window->on_btn_close_pressed)
		window->on_btn_close_pressed(window);
}

int mlx_window_key_pressed_handler(int keycode, t_mlx_window *window)
{
	if (window->on_key_pressed)
		window->on_key_pressed(window, keycode, window->on_key_pressed_arg);
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
	mlx_hook(w->addr, DestroyNotify, ButtonPressMask, &mlx_window_close_btn_pressed_handler, w);
	mlx_hook(w->addr, KeyPress, KeyPressMask, &mlx_window_on_key_down_handler, w);
	mlx_hook(w->addr, KeyRelease, KeyReleaseMask, &mlx_window_on_key_up_handler, w);
	mlx_key_hook(w->addr, mlx_window_key_pressed_handler, w);
	mlx_expose_hook(w->addr, mlx_window_expose_handler, w);
	if (!w->addr)
		ft_exit_err("could not create new mlx window.");
	return (w);
}



t_color	new_color(t_uchar a, t_uchar r, t_uchar g, t_uchar b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_vector	ft_vector_add(t_vector self, t_vector v2)
{
	self.x += v2.x;
	self.y += v2.y;
	return (self);
}

t_str	ft_vector_to_str(t_vector vector)
{
	return (ft_str_format("(%f, %f)", vector.x, vector.y));
}

t_vector	ft_vector_inverse(t_vector vector)
{
	vector.x = 1 / vector.x;
	vector.y = 1 / vector.y;
	return (vector);
}

t_vector	ft_vector_mult(t_vector vector, t_vector factor)
{
	vector.x *= factor.x;
	vector.y *= factor.y;
	return (vector);
}

t_vector	new_vector_2(float x, float y);

t_vector	ft_vector_mult_scalar(t_vector vector, float factor)
{
	return (vector.mult(vector, new_vector_2(factor, factor)));
}

t_vector	ft_vector_divide(t_vector vector, t_vector factor)
{
	return (vector.mult(vector, factor.inverse(factor)));
}

t_vector	new_vector_2(float x, float y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = 0;
	v.add = &ft_vector_add;
	v.inverse = &ft_vector_inverse;
	v.mult = &ft_vector_mult;
	v.mult_scalar = &ft_vector_mult_scalar;
	v.divide = &ft_vector_divide;
	v.to_str = &ft_vector_to_str;
	return (v);
}

t_vector	new_vector_3(float x, float y, float z)
{
	t_vector	v;

	v = new_vector_2(x, y);
	v.z = z;
	return (v);
}

t_uchar 	*ft_img_get_pixel_addr(t_mlx_img *img, t_vector pos)
{
	return (t_uchar *) (img->data + (int) pos.y * img->line_size + (int) pos.x * (img->bits_per_pixel / 8));
}
t_color	ft_img_get_pixel(t_mlx_img *img, t_vector pos)
{
	if (pos.x > img->size.x || pos.y > img->size.y)
		return (new_color(255, 0, 0, 0));
	return (new_color(
			*(ft_img_get_pixel_addr(img, pos) + 3),
			*(ft_img_get_pixel_addr(img, pos) + 2),
			*(ft_img_get_pixel_addr(img, pos) + 1),
			*(ft_img_get_pixel_addr(img, pos) + 0)
			));
}
void	ft_img_set_pixel(t_mlx_img *img, t_vector pos, t_color color)
{
	if (pos.x > img->size.x || pos.y > img->size.y)
		return ;
	*(ft_img_get_pixel_addr(img, pos) + 3) = color.a;
	*(ft_img_get_pixel_addr(img, pos) + 2) = color.r;
	*(ft_img_get_pixel_addr(img, pos) + 1) = color.g;
	*(ft_img_get_pixel_addr(img, pos) + 0) = color.b;
}

void	ft_img_draw_img(t_mlx_img *self, t_mlx_img *to_draw, t_vector origin)
{
	for (int y = 0; y < to_draw->size.y; ++y)
	{
		for (int x = 0; x < to_draw->size.x; ++x)
		{
			t_vector pos = new_vector_2(x, y);
			t_color pixel = to_draw->get_pixel(to_draw, pos);
			if (pixel.a == 255) continue ;
			self->set_pixel(self, pos.add(pos, origin), pixel);
		}
	}
}

t_mlx_img	*ft_img_resize(t_mlx_img *self, t_vector new_size)
{
	t_vector scale = new_size.divide(new_size, self->size);
	t_mlx_img *cpy = self->client->img_empty(self->client, new_size);
	for (int py = 0; py < self->size.y * scale.y; ++py)
	{
		for (int px = 0; px < self->size.x * scale.x; ++px)
		{
			t_vector pos = new_vector_2(px, py);
			t_color pixel = self->get_pixel(self, pos.divide(pos, scale));
			cpy->set_pixel(cpy, pos, pixel);
		}
	}
	return (cpy);
}

t_mlx_img	*new_img(t_mlx_client *client)
{
	t_mlx_img	*img = ft_safe_malloc(sizeof(t_mlx_img));

	img->client = client;
	img->size = new_vector_2(0, 0);
	img->draw_img = &ft_img_draw_img;
	img->get_pixel = &ft_img_get_pixel;
	img->set_pixel = &ft_img_set_pixel;
	img->resize = &ft_img_resize;
	return (img);
}

t_mlx_img	*ft_mlx_client_img_empty(t_mlx_client *client, t_vector size)
{
	t_mlx_img	*img = new_img(client);

	img->size = size;
	img->addr = mlx_new_image(client->addr, img->size.x, img->size.y);
	img->data = mlx_get_data_addr(img->addr, &img->bits_per_pixel, &img->line_size, (int *)&img->endian);
	return (img);
}

t_mlx_img	*ft_mlx_client_img_from_file(t_mlx_client *client, t_str file_path)
{
	t_mlx_img	*img = new_img(client);

	int width, height;
	img->addr = mlx_xpm_file_to_image(client->addr, file_path, &width, &height);
	img->size = new_vector_2(width, height);
	img->data = mlx_get_data_addr(img->addr, &img->bits_per_pixel, &img->line_size, (int *)&img->endian);
	return (img);
}

void ft_mlx_client_listen_for_input(t_mlx_client *self)
{
	mlx_loop(self->addr);
}

t_mlx_client	*new_mlx_client()
{
	t_mlx_client	*client = ft_safe_malloc(sizeof(t_mlx_client));

	client->addr = mlx_init();
	client->new_window = &new_mlx_window;
	client->img_empty = &ft_mlx_client_img_empty;
	client->img_from_file = &ft_mlx_client_img_from_file;
	client->listen_for_input = &ft_mlx_client_listen_for_input;
	if (!client->addr)
		ft_exit_err("could not initiate mlx connection.");
	return (client);
}

t_str	ft_color_to_str(t_color color)
{
	return (ft_str_format("argb(%d, %d, %d, %d)", color.a, color.r, color.g, color.b));
}

t_game_object *new_game_object()
{
	t_game_object *g = ft_safe_malloc(sizeof(t_game_object));

	g->transform = new_vector_3(0, 0, 0);
	g->sprite = NULL;
}

t_scene	*new_scene()
{
	t_scene *s = ft_safe_malloc(sizeof(t_scene));

	s->game_objects = new_list();
	return (s);
}

int ft_game_render(t_mlx_window *win, t_game *game)
{
	game->tick++;
	if (game->tick % 10 == false) return;
	t_mlx_client *client = win->client;
	t_mlx_img *canvas = client->img_empty(client, new_vector_2(1000, 500));
	t_iterator *i = game->curr_scene->game_objects->get_iterator(game->curr_scene->game_objects);

	while (i->next(i))
	{
		t_game_object *o = i->curr->data->value;
		if (o->sprite)
		{
			canvas->draw_img(canvas, o->sprite, o->transform);
		}
	}
	win->put_img(win, canvas, new_vector_2(0, 0));
}

void	ft_game_listen_for_inputs(t_game *self)
{
	self->mlx_client->listen_for_input(self->mlx_client);
}

int	ft_game_on_key_pressed_handler(t_mlx_window *window, int key, t_game *game)
{
	if (game->on_key_pressed)
		game->on_key_pressed(window, key, game);
}

void	ft_game_start(t_game *self)
{
	self->curr_scene = new_scene();
	self->window = self->mlx_client->new_window(self->mlx_client, new_vector_2(1000, 500), "New Game");
	self->window->on_expose = &ft_game_render;
	self->window->on_expose_arg = self;
	self->window->on_key_pressed = &ft_game_on_key_pressed_handler;
	self->window->on_key_pressed_arg = self;
}

t_game *new_game()
{
	t_game *g = ft_safe_malloc(sizeof(t_game));

	g->mlx_client = new_mlx_client();
	g->tick = 0;
	return (g);
}

int	on_btn_close_pressed(t_mlx_window *window)
{
	exit(0);
}

void	on_key_pressed(t_mlx_window *window, int key, t_game *game)
{
	game->tick++;
	if (key == XK_Escape)
		on_btn_close_pressed(window);

	t_link *o = game->curr_scene->game_objects->get_elem(game->curr_scene->game_objects, 0);
	if (!o) return;

	t_vector direction = new_vector_2(0, 0);
	if (key == XK_Up) direction.y = -1;
	if (key == XK_Down) direction.y = 1;
	if (key == XK_Left) direction.x = -1;
	if (key == XK_Right) direction.x = 1;
	t_vector speed = new_vector_2(10, 10);
	t_game_object *obj = o->data->value;
	obj->transform = obj->transform.add(obj->transform, speed.mult(speed, direction));
	ft_game_render(window, game);
}

int	main(int argc, t_str *argv)
{
	t_game *game = new_game();
	ft_game_start(game);

	game->window->on_btn_close_pressed = &on_btn_close_pressed;
	game->on_key_pressed = &on_key_pressed;

	t_game_object *brigitte = new_game_object();
	brigitte->sprite = game->mlx_client->img_from_file(game->mlx_client, "src/brigitte.xpm");
	game->curr_scene->game_objects->push_data(game->curr_scene->game_objects, new_typed_ptr(T_TYPE_UNKNOWN, brigitte));

	ft_game_listen_for_inputs(game);
	ft_unused("", argc, argv);
}
