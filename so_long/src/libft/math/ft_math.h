/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:11:43 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "../libft.h"

# define PI 3.1415

t_llong	    ft_math_abs(t_llong nb);
t_ldouble   ft_math_abs_double(t_ldouble nb);
t_llong	    ft_math_clamp(t_llong nb, t_llong min, t_llong max);
double      ft_math_fmod(double a, double d);
double      ft_math_fractional_part(double x);
t_llong	    ft_math_max(t_llong a, t_llong b);
t_llong	    ft_math_min(t_llong a, t_llong b);
t_llong	    ft_math_pow(t_llong nb, int pow);
float       ft_math_sin(float x);

#endif
