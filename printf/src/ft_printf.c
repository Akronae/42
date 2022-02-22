/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
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
#include "ft_template_type.h"
#include "ft_formatted_element.h"
#include <stdarg.h>
#include "libft/list/ft_list.h"
#include "libft/string/ft_string.h"

struct t_list	*ft_parse_args(va_list args, const char *input)
{
	t_list			*list;
	size_t			i;
	t_template_type	type;

	list = new_list();
	if (!list)
		return (NULL);
	i = 0;
	while (input[i])
	{
		list->push(list);
		if (input[i] == '%')
		{
			i += 1;
			type = ft_template_type_from_char(input[i]);
			list->last_element->data = ft_arg_to_formatted_elem(args, type);
		}
		else
			list->last_element->data = ft_char_to_formatted_elem(input[i]);
		i++;
	}
	return (list);
}

int	ft_printf(const char *input, ...)
{
	va_list				args;
	t_list				*list;
	size_t				output_str_len;
	size_t				i;
	t_formatted_element	*f;

	va_start(args, input);
	list = ft_parse_args(args, input);
	list->on_elem_free = ft_formatted_list_free_elem;
	va_end(args);
	output_str_len = 0;
	i = 0;
	while (i < list->length)
	{
		f = list->get_elem(list, i)->data;
		output_str_len += f->length;
		write(1, f->value, f->length);
		i++;
	}
	list->free(list);
	return (output_str_len);
}
