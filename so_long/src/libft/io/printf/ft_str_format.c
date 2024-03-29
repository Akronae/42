/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "../../list/ft_list.h"
#include "../../string/ft_string.h"

t_link	*ft_map_formatted_to_str(t_link *elem)
{
	t_formatted_element	*curr;
	t_link				*new;

	if (!elem || !elem->data || !elem->data->value)
		return (NULL);
	curr = elem->data->value;
	new = new_link();
	new->set_data(new, new_typed_ptr_str(ft_strdup(curr->value)));
	return (new);
}

t_str	ft_str_format_handle_args(t_str input, va_list args)
{
	t_list	*list;
	t_str	str;

	list = ft_printf_parse_args(args, (t_str) input);
	list = list->map(list, &ft_map_formatted_to_str);
	str = list->join(list, STRING_EMPTY);
	list->free(list);
	return (str);
}

t_str	ft_str_format(t_str input, ...)
{
	va_list	args;
	t_str	str;

	va_start(args, input);
	str = ft_str_format_handle_args(input, args);
	va_end(args);
	return (str);
}
