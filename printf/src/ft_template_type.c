/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_template_type_from_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_template_type.h"

enum t_template_type	ft_template_type_from_char(char c)
{
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'd')
		return (DECIMAL);
	if (c == 'i')
		return (INT);
	if (c == 'u')
		return (U_DECIMAL);
	if (c == 'x')
		return (HEXADECIMAL);
	if (c == 'X')
		return (UPPER_HEXADECIMAL);
	if (c == '%')
		return (PERCENT);
	return (-1);
}
