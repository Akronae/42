/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 14:51:51 by adaubric         ###   ########.fr       */
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

enum t_type ft_type_from_char(const char c)
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
	return (-1);
}

char *ulonglong_to_str(unsigned long long nb)
{
	t_list *list = new_list();
	while (nb)
	{
		list->push_char(list, nb % 10 + '0');
		nb /= 10;
	}
	char *str = malloc(sizeof(char) * (list->length + 1));
	size_t i = 0;
	t_link *elem = list->last_element;
	while (TRUE)
	{
		str[i] = *((char *) elem->data);
		i++;
		if (!elem->prev)
			break;
		elem = elem->prev;
	}
	str[i] = '\0';
	list->free(list);
	return str;
}

char *ft_arg_to_str(va_list args, enum t_type type)
{
	char *str;

	str = NULL;
	if (type == CHAR)
		str = ft_char_to_str(va_arg(args, int));
	if (type == INT)
		str = ft_itoa(va_arg(args, int));
	if (type == STRING)
		str = ft_strdup(va_arg(args, char *));
	if (type == POINTER)
		str = ft_hex_str_from_ull(va_arg(args, unsigned long long));
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