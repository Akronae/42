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

#include "../libft.h"

llong	ft_math_abs(llong nb);
llong	ft_math_clamp(llong nb, llong min, llong max);
llong	ft_math_max(llong a, llong b);
llong	ft_math_min(llong a, llong b);
llong	ft_math_pow(llong nb, int pow);

#endif
