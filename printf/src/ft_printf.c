/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/21 15:32:38 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_template_type.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include "libft/boolean/ft_boolean.h"
#include "libft/link/ft_link.h"
#include "libft/list/ft_list.h"
#include "libft/iterator/ft_iterator.h"
#include "libft/char/ft_char.h"
#include "libft/hex/ft_hex.h"
#include "libft/number/ft_number.h"
#include "libft/string/ft_string.h"
#include "libft/io/ft_io.h"

char *ft_arg_to_str(va_list args, enum t_template_type type)
{
	char *str;

	str = NULL;
	if (type == CHAR)
		str = ft_char_to_str(va_arg(args, int));
	if (type == INT || type == DECIMAL)
		str = ft_number_to_str(va_arg(args, int));
	if (type == STRING)
		str = ft_strdup(va_arg(args, char *));
	if (type == POINTER)
	{
		char *hex = ft_hex_str_from_nbr(va_arg(args, unsigned long long));
		str = ft_strjoin("0x", hex);
		free(hex);
	}
	if (type == U_DECIMAL)
		str = ft_number_to_str(va_arg(args, unsigned int));
	if (type == HEXADECIMAL || type == UPPER_HEXADECIMAL)
	{
		str = ft_hex_str_from_nbr(va_arg(args, unsigned int));
		if (type == UPPER_HEXADECIMAL)
			ft_string_to_upper(str);
	}
	if (type == PERCENT)
		str = ft_strdup("%");
	return (str);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int i = -1;
	t_list *a = new_list();

	va_start(args, input);
	while (input[++i])
	{
		if (input[i] == '%')
		{
			i += 1;
			t_template_type type = ft_template_type_from_char(input[i]);
			char *str = ft_arg_to_str(args, type);
			a->push_str(a, str);
		}
		else
			a->push_char(a, input[i]);
	}
	va_end(args);

	char *output_str = a->join(a, "");
	sizeof output_str_len = ft_strlen(output_str);
	ft_putstr_fd(output_str, 1);
	a->free(a);
	free(output_str);

	return (output_str_len);
}