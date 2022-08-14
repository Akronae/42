/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_img.h"
#include "../libft/libft.h"
#include "../libft/memory/ft_memory.h"
#include "../libft/math/ft_math.h"
#include "../libft/io/ft_io.h"
#include "../minilibx-linux/mlx.h"
#include "keysymdef.h"
#include <stdlib.h>
#include <X11/X.h>

t_uchar 	*ft_mlx_img_get_pixel_addr(t_mlx_img *img, t_vector pos)
{
	return (t_uchar *) (img->data + (int) pos.y * img->line_size + (int) pos.x * (img->bits_per_pixel / 8));
}

t_color	ft_mlx_img_get_pixel(t_mlx_img *img, t_vector pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x > img->size.x || pos.y > img->size.y)
		return (new_color(255, 0, 0, 0));
	return (new_color(
			*(ft_mlx_img_get_pixel_addr(img, pos) + 3),
			*(ft_mlx_img_get_pixel_addr(img, pos) + 2),
			*(ft_mlx_img_get_pixel_addr(img, pos) + 1),
			*(ft_mlx_img_get_pixel_addr(img, pos) + 0)
			));
}
void	ft_mlx_img_set_pixel(t_mlx_img *img, t_vector pos, t_color color)
{
	if (pos.x < 0 || pos.y < 0 || pos.x > img->size.x || pos.y > img->size.y)
		return ;
	*(ft_mlx_img_get_pixel_addr(img, pos) + 3) = color.a;
	*(ft_mlx_img_get_pixel_addr(img, pos) + 2) = color.r;
	*(ft_mlx_img_get_pixel_addr(img, pos) + 1) = color.g;
	*(ft_mlx_img_get_pixel_addr(img, pos) + 0) = color.b;
}

void	ft_mlx_img_draw_img(t_mlx_img *self, t_mlx_img *to_draw, t_vector origin)
{
	for (int y = 0; y < ft_math_abs(to_draw->size.y * to_draw->scale.y); ++y)
	{
		for (int x = 0; x < ft_math_abs(to_draw->size.x * to_draw->scale.x); ++x)
		{
			t_vector draw_pos = new_vector_2(x, y);
			t_vector sample_pos = draw_pos.divide(draw_pos, to_draw->scale);
			if (sample_pos.x < 0)
				sample_pos.x += ft_math_abs(to_draw->size.x * to_draw->scale.x) * -1 / to_draw->scale.x;
			if (sample_pos.y < 0)
				sample_pos.y += ft_math_abs(to_draw->size.y * to_draw->scale.y) * -1 / to_draw->scale.y;
			t_color sample_pixel = to_draw->get_pixel(to_draw, sample_pos);
			if (sample_pixel.a == 255)
				continue ;
			self->set_pixel(self, draw_pos.add(draw_pos, origin), sample_pixel);
		}
	}
}

t_mlx_img	*ft_mlx_img_resize(t_mlx_img *self, t_vector new_size)
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
	img->scale = new_vector_2(1, 1);
	img->draw_img = &ft_mlx_img_draw_img;
	img->get_pixel = &ft_mlx_img_get_pixel;
	img->set_pixel = &ft_mlx_img_set_pixel;
	img->resize = &ft_mlx_img_resize;
	return (img);
}
