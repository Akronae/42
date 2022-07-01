/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/21 20:02:57 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "../../hex/ft_hex.h"
#include "../../memory/ft_memory.h"

t_str	ft_arg_str_to_str(t_str str)
{
	if (!str)
		str = "(null)";
	return (ft_strdup(str));
}

t_str	ft_arg_ptr_to_str(t_ullong ptr)
{
	t_str	hex;
	t_str	str;

	if (!ptr)
		return (ft_strdup(NULL_PTR_DISPLAY));
	hex = ft_hex_str_from_nbr(ptr);
	str = ft_strjoin("0x", hex);
	ft_safe_free(hex);
	return (str);
}

t_str	ft_arg_hex_to_str(t_uint val, t_template_type type)
{
	t_str	str;

	str = ft_hex_str_from_nbr(val);
	if (type == UPPER_HEXADECIMAL)
		ft_string_to_upper(str);
	return (str);
}
