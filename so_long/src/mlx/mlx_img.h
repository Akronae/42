/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

# include "../libft/libft.h"
# include "vector.h"
# include "color.h"
# include "mlx_client.h"

typedef struct t_mlx_img
{
	struct t_mlx_client	*client;
	char				*addr;
	char				*data;
	int					bits_per_pixel;
	int 				line_size;
	t_vector			size;
	t_bool				endian;
	t_vector			scale;
	void				(*draw_img)(struct t_mlx_img *self, struct t_mlx_img *to_draw, t_vector origin);
	t_color				(*get_pixel)(struct t_mlx_img *self, t_vector pos);
	void 				(*set_pixel)(struct t_mlx_img *self, t_vector pos, t_color pixel);
	struct t_mlx_img 	*(*resize)(struct t_mlx_img *self, t_vector new_size);
}	t_mlx_img;

t_uchar 	*ft_mlx_img_get_pixel_addr(t_mlx_img *img, t_vector pos);
t_color		ft_mlx_img_get_pixel(t_mlx_img *img, t_vector pos);
void		ft_mlx_img_set_pixel(t_mlx_img *img, t_vector pos, t_color color);
void		ft_mlx_img_draw_img(t_mlx_img *self, t_mlx_img *to_draw, t_vector origin);
t_mlx_img	*ft_mlx_img_resize(t_mlx_img *self, t_vector new_size);
t_mlx_img	*new_img(struct t_mlx_client *client);

#endif