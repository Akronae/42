/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 17:23:47 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_type.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include "ft_boolean.h"
#include "ft_link.h"
#include "ft_list.h"
#include "ft_iterator.h"
#include "ft_char.h"
#include "ft_hex.h"
#include "ft_long.h"
#include "ft_str.h"

enum t_type ft_type_from_char(char c)
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

char *ft_arg_to_str(va_list args, enum t_type type)
{
	char *str;

	str = NULL;
	if (type == CHAR)
		str = ft_char_to_str(va_arg(args, int));
	if (type == INT || type == DECIMAL)
		str = ft_nbr_to_str(va_arg(args, int));
	if (type == STRING)
		str = ft_strdup(va_arg(args, char *));
	if (type == POINTER)
	{
		char *hex = ft_hex_str_from_nbr(va_arg(args, unsigned long long));
		str = ft_strjoin("0x", hex);
		free(hex);
	}
	if (type == U_DECIMAL)
		str = ft_nbr_to_str(va_arg(args, unsigned int));
	if (type == HEXADECIMAL || type == UPPER_HEXADECIMAL)
	{
		str = ft_hex_str_from_nbr(va_arg(args, unsigned int));
		if (type == UPPER_HEXADECIMAL)
			ft_str_to_upper(str);
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
			t_type type = ft_type_from_char(input[i]);
			char *str = ft_arg_to_str(args, type);
			a->push_str(a, str);
		}
		else
			a->push_str(a, ft_char_to_str(input[i]));
	}
	va_end(args);

	t_iterator *iterator = a->get_iterator(a);
	while (iterator->current)
	{
		ft_putstr_fd(iterator->next(iterator), 0);
	}
	a->free(a);
	iterator->free(iterator);

	return (0);
}