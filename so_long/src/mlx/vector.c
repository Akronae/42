/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "../libft/io/ft_io.h"

t_vector	ft_vector_add(t_vector self, t_vector v2)
{
	self.x += v2.x;
	self.y += v2.y;
	return (self);
}

t_vector	ft_vector_add_scalar(t_vector self, double add)
{
	return (self.add(self, new_vector_2(add, add)));
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

t_vector	ft_vector_mult_scalar(t_vector vector, double factor)
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
