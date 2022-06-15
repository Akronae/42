/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/21 20:02:57 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "../../hex/ft_hex.h"
#include "../../string/ft_string.h"

t_string 	ft_arg_str_to_str(t_string str)
{
	if (!str)
		str = "(null)";
	return (ft_strdup(str));
}

t_string 	ft_arg_ptr_to_str(unsigned long long ptr)
{
	t_string 	hex;
	t_string 	str;

	if (!ptr)
		return (ft_strdup(NULL_PTR_DISPLAY));
	hex = ft_hex_str_from_nbr(ptr);
	str = ft_strjoin("0x", hex);
	free(hex);
	return (str);
}

t_string 	ft_arg_hex_to_str(unsigned int val, t_template_type type)
{
	t_string 	str;

	str = ft_hex_str_from_nbr(val);
	if (type == UPPER_HEXADECIMAL)
		ft_string_to_upper(str);
	return (str);
}
