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

#include "color.h"
#include "../libft/libft.h"
#include "../libft/io/ft_io.h"

t_str	ft_color_to_str(t_color color)
{
	return (ft_str_format("argb(%d, %d, %d, %d)", color.a, color.r, color.g, color.b));
}

t_color	new_color(t_uchar a, t_uchar r, t_uchar g, t_uchar b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	color.to_str = &ft_color_to_str;
	return (color);
}
