/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "../libft/string/ft_string.h"

typedef struct t_vector
{
	float x;
	float y;
	float z;
	struct t_vector	(*add)(struct t_vector self, struct t_vector v2);
	struct t_vector	(*add_scalar)(struct t_vector self, double add);
	struct t_vector	(*inverse)(struct t_vector self);
	struct t_vector	(*mult)(struct t_vector self, struct t_vector factor);
	struct t_vector	(*mult_scalar)(struct t_vector self, double factor);
	struct t_vector	(*divide)(struct t_vector self, struct t_vector factor);
	t_str			(*to_str)(struct t_vector self);
}	t_vector;

t_vector	ft_vector_add(t_vector self, t_vector v2);
t_vector	ft_vector_add_scalar(t_vector self, double add);
t_str		ft_vector_to_str(t_vector vector);
t_vector	ft_vector_inverse(t_vector vector);
t_vector	ft_vector_mult(t_vector vector, t_vector factor);
t_vector	ft_vector_mult_scalar(t_vector vector, double factor);
t_vector	ft_vector_divide(t_vector vector, t_vector factor);
t_vector	new_vector_2(float x, float y);
t_vector	new_vector_3(float x, float y, float z);

#endif