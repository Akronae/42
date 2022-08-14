/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_client.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CLIENT_H
# define MLX_CLIENT_H

# include "vector.h"
# include "mlx_img.h"
# include "mlx_window.h"
# include "../libft/string/ft_string.h"

typedef struct t_mlx_client
{
	void				*addr;
	struct t_mlx_window	*(*new_window)(struct t_mlx_client *self, t_vector size, t_str title);
	struct t_mlx_img 	*(*img_empty)(struct t_mlx_client *self, t_vector size);
	struct t_mlx_img 	*(*img_from_file)(struct t_mlx_client *self, t_str file_path);
	void 				(*listen_for_input)(struct t_mlx_client *self);
} t_mlx_client;

struct t_mlx_img		*ft_mlx_client_img_empty(t_mlx_client *client, t_vector size);
struct t_mlx_img		*ft_mlx_client_img_from_file(t_mlx_client *client, t_str file_path);
void			ft_mlx_client_listen_for_input(t_mlx_client *self);
t_mlx_client	*new_mlx_client();

#endif