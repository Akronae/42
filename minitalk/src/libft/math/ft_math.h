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

t_llong	ft_math_abs(t_llong nb);
t_llong	ft_math_clamp(t_llong nb, t_llong min, t_llong max);
t_llong	ft_math_max(t_llong a, t_llong b);
t_llong	ft_math_min(t_llong a, t_llong b);
t_llong	ft_math_pow(t_llong nb, int pow);

#endif
