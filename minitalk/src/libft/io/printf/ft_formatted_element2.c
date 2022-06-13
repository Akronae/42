/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatted_element2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/23 14:59:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../../number/ft_number.h"
#include "../../string/ft_string.h"
#include <stdarg.h>

void	ft_arg_to_formatted_elem2(va_list args,
		enum t_template_type type, t_formatted_element *elem)
{
	if (type == POINTER)
		elem->value = ft_arg_ptr_to_str(va_arg(args, unsigned long long));
	else if (type == U_DECIMAL)
		elem->value = ft_number_to_str(va_arg(args, unsigned int));
	else if (type == PERCENT)
		elem->value = ft_strdup("%");
	else if (type == LONGLONG)
		elem->value = ft_number_to_str(va_arg(args, long long));
	else if (type == HEXADECIMAL || type == UPPER_HEXADECIMAL)
		elem->value = ft_arg_hex_to_str(va_arg(args, unsigned int), type);
}
