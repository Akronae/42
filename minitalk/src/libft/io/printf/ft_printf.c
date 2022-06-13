/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "../../string/ft_string.h"
#include "../../memory/ft_memory.h"

void	ft_printf_parse_args_handle_char(va_list args, t_list *list,
	char *input, size_t *index)
{
	t_template_type	type;
	int				should_free_arg;

	if (input[*index] == '%')
	{
		type = ft_template_type_from_str(input, index);
		should_free_arg = ft_str_index_of(FLAG_FREE, input + *index) == 1;
		if (should_free_arg)
			*index += ft_strlen(FLAG_FREE);
		list->push_data(list, new_typed_ptr(T_TYPE_UNKNOWN,
				ft_arg_to_formatted_elem(args, type, should_free_arg)));
	}
	else
		list->push_data(list, new_typed_ptr(T_TYPE_UNKNOWN,
				ft_char_to_formatted_elem(input[*index])));
}

struct t_list	*ft_printf_parse_args(va_list args, char *input)
{
	t_list			*list;
	size_t			i;

	list = new_list();
	list->on_elem_free = &ft_formatted_list_free_elem;
	if (!input)
		return (list);
	i = 0;
	while (input[i])
	{
		ft_printf_parse_args_handle_char(args, list, input, &i);
		i++;
	}
	return (list);
}

int	ft_print(const char *input, va_list args)
{
	t_list				*list;
	size_t				output_str_len;
	size_t				i;
	t_formatted_element	*f;

	list = ft_printf_parse_args(args, (char *) input);
	output_str_len = 0;
	i = 0;
	while (i < list->length)
	{
		f = list->get_elem(list, i)->data->value;
		output_str_len += f->length;
		write(1, f->value, f->length);
		i++;
	}
	list->free(list);
	return (output_str_len);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	output_str_len;

	va_start(args, input);
	output_str_len = ft_print(input, args);
	va_end(args);
	return (output_str_len);
}

int	ft_printfl(const char *input, ...)
{
	va_list	args;
	size_t	output_str_len;
	char	*final_str;

	va_start(args, input);
	final_str = ft_strjoin(input, "\n");
	output_str_len = ft_print(final_str, args);
	ft_safe_free(final_str);
	va_end(args);
	return (output_str_len);
}
