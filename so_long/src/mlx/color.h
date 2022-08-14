/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../libft/libft.h"
# include "../libft/string/ft_string.h"

typedef struct t_color
{
	t_uchar a;
	t_uchar r;
	t_uchar g;
	t_uchar b;
	t_str	(*to_str)(struct t_color *self);
}	t_color;

t_str	ft_color_to_str(t_color color);
t_color	new_color(t_uchar a, t_uchar r, t_uchar g, t_uchar b);
#endif