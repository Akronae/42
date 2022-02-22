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
#include "ft_printf.h"
#include "ft_template_type.h"
#include "libft/libft.h"
#include <stdarg.h>
#include "libft/boolean/ft_boolean.h"
#include "libft/link/ft_link.h"
#include "libft/list/ft_list.h"
#include "libft/iterator/ft_iterator.h"
#include "libft/char/ft_char.h"
#include "libft/hex/ft_hex.h"
#include "libft/number/ft_number.h"
#include "libft/string/ft_string.h"
#include "libft/io/ft_io.h"

static char	*ft_arg_str_to_str(char *str)
{
	if (!str)
		str = "(null)";
	return (ft_strdup(str));
}

static char	*ft_arg_ptr_to_str(unsigned long long ptr)
{
	char	*hex;
	char	*str;

	if (!ptr)
		return (ft_strdup("(nil)"));
	hex = ft_hex_str_from_nbr(ptr);
	str = ft_strjoin("0x", hex);
	free(hex);
	return (str);
}

static char	*ft_arg_to_str(va_list args, enum t_template_type type)
{
	char	*str;

	str = NULL;
	if (type == CHAR)
		str = ft_char_to_str(va_arg(args, int));
	if (type == INT || type == DECIMAL)
		str = ft_number_to_str(va_arg(args, int));
	if (type == STRING)
		str = ft_arg_str_to_str(va_arg(args, char *));
	if (type == POINTER)
		str = ft_arg_ptr_to_str(va_arg(args, unsigned long long));
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

static t_list	*ft_parse_args(va_list args, const char *input, size_t *a)
{
	t_list	*list;
	size_t	i;
	char	*str;

	list = new_list();
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i += 1;
			str = ft_arg_to_str(args, ft_template_type_from_char(input[i]));
			list->push_str(list, str);
			if (!*str)
				*a += 1;
		}
		else
			list->push_char(list, input[i]);
		i++;
	}
	return (list);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	t_list	*list;
	size_t	empty_count;
	char	*output_str;
	size_t	output_str_len;

	empty_count = 0;
	va_start(args, input);
	list = ft_parse_args(args, input, &empty_count);
	va_end(args);
	output_str = list->join(list, "");
	output_str_len = ft_strlen(output_str) + empty_count;
	ft_putstr_fd(output_str, 1);
	list->free(list);
	free(output_str);
	return (output_str_len);
}
