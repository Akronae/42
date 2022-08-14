/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_sin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float ft_math_sin(float x)
{
	x = ft_math_fmod(x, PI);
  float res=0, pow=x, fact=1;
  for(int i=0; i<5; ++i)
  {
    res+=pow/fact;
    pow*=-1*x*x;
    fact*=(2*(i+1))*(2*(i+1)+1);
  }

  return res;
}