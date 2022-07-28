/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"
#include "../io/ft_io.h"

t_str	ft_double_to_str(double d)
{
	int decimal_part = (int) d;
	float tenth_part = d - decimal_part;
	t_str str = ft_str_format("%d.%d", decimal_part, (int) (tenth_part * 10000));
	while (str && str[ft_strlen(str) - 1] == '0')
	{
		if (str[ft_strlen(str) - 2] == '.')
			break ;
		str[ft_strlen(str) - 1] = '\0';
	}
	return (str);
}
