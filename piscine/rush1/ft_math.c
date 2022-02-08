/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:51:20 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 21:51:22 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	if (i >= 1 && i <= 9)
		return (i);
	else
		return (0);
}