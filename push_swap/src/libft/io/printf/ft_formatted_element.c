/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatted_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/23 14:59:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../../string/ft_string.h"
#include "../../char/ft_char.h"
#include "../../number/ft_number.h"
#include <stdlib.h>
#include <stdarg.h>

struct t_formatted_element	*new_formatted_element(void)
{
	t_formatted_element	*elem;

	elem = malloc(sizeof(t_formatted_element));
	if (!elem)
		return (NULL);
	elem->value = NULL;
	elem->length = 0;
	return (elem);
}

void	ft_formatted_list_free_elem(t_link *elem)
{
	t_formatted_element	*data;

	data = elem->data;
	if (data && data->value)
		free(data->value);
}

struct t_formatted_element	*ft_arg_to_formatted_elem(va_list args,
		enum t_template_type type)
{
	t_formatted_element	*elem;

	elem = new_formatted_element();
	if (!elem)
		return (NULL);
	if (type == CHAR)
	{
		elem->value = ft_char_to_str(va_arg(args, int));
		elem->length = 1;
	}
	else if (type == INT || type == DECIMAL)
		elem->value = ft_number_to_str(va_arg(args, int));
	else if (type == LONGLONG)
		elem->value = ft_number_to_str(va_arg(args, long long));
	else if (type == STRING)
		elem->value = ft_arg_str_to_str(va_arg(args, char *));
	else if (type == POINTER)
		elem->value = ft_arg_ptr_to_str(va_arg(args, unsigned long long));
	else if (type == U_DECIMAL)
		elem->value = ft_number_to_str(va_arg(args, unsigned int));
	else
		ft_arg_to_formatted_elem2(args, type, elem);
	if (!elem->length)
		elem->length = ft_strlen(elem->value);
	return (elem);
}

struct t_formatted_element	*ft_char_to_formatted_elem(char c)
{
	t_formatted_element	*elem;

	elem = new_formatted_element();
	elem->length = 1;
	elem->value = ft_char_to_str(c);
	return (elem);
}