/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_client.h"
#include "../libft/libft.h"
#include "../libft/memory/ft_memory.h"
#include "../libft/io/ft_io.h"
#include "../minilibx-linux/mlx.h"
#include "keysymdef.h"
#include <stdlib.h>
#include <X11/X.h>

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
